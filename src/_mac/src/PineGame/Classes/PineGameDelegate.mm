#import "PineGameDelegate.h"
#import "EAGLView.h"
#import "CGame.h"
#import "Os_Functions.h"
#import "GameCenterManager.h"
#import <UIKit/UIView.h>
extern "C" void DevicePushRemoteNotification(char* device_token,char *message);
extern "C" bool OS_IsNetworkAvailable();
extern "C" bool isGCAvailable();
extern "C" void InitGCBoard();
extern const char* _tmpString = NULL;
extern const char* _tmpString2 = NULL;
extern  int _resume_count = 0;
extern int	_tmpnum = 0;
extern "C" void GamePause();
extern "C" void GameResume();
extern "C" void GameExit();
extern "C" void StartThread();
PineGameDelegate *g_PineGameInstance = nil;
extern "C" void EndGame();
@implementation PineGameDelegate
extern "C" bool HasOpenFeintInit();
extern "C" void ShutdownIfNotOnline();
extern "C" int  GetMotionAnchor();
extern "C" void SetMotionAnchor(int anchor);
extern "C" void InitInAppPurchase();
@synthesize AppPurchase;
@synthesize window;
@synthesize glView;
@synthesize _opgenGLESViewController;
UIBackgroundTaskIdentifier bgTask = NULL;
extern "C" const char* OS_GetDeviceUserAgent();

#include "PineMacOSFunc.h"
#if ADD_CHARTBOOST
#include "PineChartBoost.h"
#endif
#if ADD_IADVERT
#include "PineIAdvert.h"
#endif
#if USE_ADBOX
extern "C" void OS_AdBoxDownloadFile();
#endif

extern "C" const  char* GetBundlePath();
extern "C" void DevicePushRemoteNotification(char* device_token,char *message);

#if ADD_UNITYADS
PineViewController* _pine_view_unityads;
NSString* _unity_app_id;
#endif
bool CGame::_force_start = false;
- (BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    NSLog(@"\nshouldAutorotateToInterfaceOrientation = %d\n",interfaceOrientation);
    return YES;
    
}


- (void) applicationDidFinishLaunching:(UIApplication*)application
{
    //printf("\nsizeof(long) = %d sizeof(int) = %d",sizeof(long),sizeof(int));
    //launch game
    _resume_count =0;
    _version_display = 0;
    g_PineGameInstance = self;
    Device::GA_Init();
    application.idleTimerDisabled = YES;
    //[[self navigationController] setNavigationBarHidden:YES animated:NO];
    [[UIApplication sharedApplication] setStatusBarHidden:YES animated:NO];
    
    [application setStatusBarOrientation:UIInterfaceOrientationPortrait animated:NO];
    [[UIApplication sharedApplication] setIdleTimerDisabled:YES];
    
#if ENABLE_SERVER_PUSH_NOTIFICATION
    [[UIApplication sharedApplication] registerForRemoteNotificationTypes:((UIRemoteNotificationType)(UIRemoteNotificationTypeBadge| UIRemoteNotificationTypeSound | UIRemoteNotificationTypeAlert))];[UIApplication sharedApplication];
#endif
    
    [self InitDisplay];
    _openfeint_init = false;
    //AppPurchase = [InAppPurchase alloc];
    
#if ADD_PICK_IMAGE
    
    _PickState =  PICK_STATE_NONE;
#endif
    //sleep(3);
    //SetMotionAnchor(MOTION_LANDSCAPE_RIGHT_ANCHOR);
    //[self InitPickImage];
    
    //sleep(3);
    

    
#if ADD_TWITTER
    tw_waccountStore = nil;
#endif
#if ADD_FACEBOOK
    fb_accountStore = nil;
#endif
    
#if ADD_SCREEN_CAPTUREVIEW
    _pine_view_captureScreen = [PineViewController alloc];
#endif
    
#if ADD_IADVERT
    _pine_view_iAD = [PineViewController alloc];
    _pine_view_iAD->requestingAd = NO;
#endif
    // _pine_view_controller = [PineViewController alloc];
    //sleep(4);
    StartThread();
    //sleep(0.8);
    CGame::_force_start = true;
    
    CGame::_this->_device.setDeviceAgent(OS_GetDeviceUserAgent());
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    /*if((SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0")))
    {
        [[UIApplication sharedApplication]  registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
    }*/
    
    TDGame*game = (TDGame*)(GAME()->_current_game);
    UIApplication*    app = [UIApplication sharedApplication];
    
    bgTask = [app beginBackgroundTaskWithExpirationHandler:^{
        [app endBackgroundTask:bgTask];
        bgTask = UIBackgroundTaskInvalid;
    }];
    GAME()->PauseEx();
    // Start the long-running task and return immediately.
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        
        // Do the work associated with the task.
        game->_play_game_num--;
        
        [app endBackgroundTask:bgTask];
        bgTask = UIBackgroundTaskInvalid;
    });
    /*if(GAME()->_musicEnable)
    {
            GAME()->PlayCurrentMusic(-1);
            GAME()->StopCurrentMusic();
    }*/
    sleep(0.1);
    printf("app did entr background");
    
}
- (void) applicationDidBecomeActive:(UIApplication*)application
{
   // [[UIApplication sharedApplication] cancelAllLocalNotifications];
    [[UIApplication sharedApplication] setApplicationIconBadgeNumber: 0];
    [[UIApplication sharedApplication] cancelAllLocalNotifications];
    GameResume();
    TDGame *game = (TDGame*)GAME()->_current_game;
  
    
    [self CleanTouch];
    if(game && game->_current_state == k_GS_PLAYGAME)
    {
        //game->ClearAllTouchUp(TOUCH_TYPE_INGAME);
        for (int j = 0; j < NUM_BUTTON_INGAME; j++)
        {
            game->_ingame_button[j].SetState(BUTTON_STATE_NORMAL);
            game->_ingame_button[j]._touch_id = -1;
            
        }
    }
#if ADD_PINE_ADVERT
    CGame::_this->_advert.SetBecomeActive();
#endif
    if(_resume_count != 0)
    {
        //UIWindow* window = [[PineGameDelegate sharedInstance] window];
        //[window bringSubviewToFront:(UIView*)[[PineGameDelegate sharedInstance] glView]];
#if USE_ADBOX
        [self AdBoxDidBecameActive:application];
#else
#if ADD_CHARTBOOST
        [self chartboostDidBecameActive:application];
#endif
#endif

        
        /*if([PineGameDelegate sharedInstance]->_motion_anchor == MOTION_LANDSCAPE_RIGHT_ANCHOR)
         {
         [[UIApplication sharedApplication] setStatusBarOrientation:UIInterfaceOrientationLandscapeRight animated:NO];
         }
         else if([PineGameDelegate sharedInstance]->_motion_anchor == MOTION_LANDSCAPE_LEFT_ANCHOR)
         {
         [[UIApplication sharedApplication] setStatusBarOrientation:UIInterfaceOrientationLandscapeLeft animated:NO];
         }*/
        
    }
    _resume_count++;
}

- (void) applicationWillResignActive:(UIApplication *)application
{
    GamePause();
    CGame::_this->_advert.ResignActive();
    [self CleanTouch];
    CGame::_this->ClearAllTouch();
    
    /*
     if(HasOpenFeintInit())
     {
     [OpenFeint shutdown];
     _openfeint_init = false;
     }
     */
    //[OpenFeint applicationWillResignActive];
}

- (void) applicationWillTerminate:(UIApplication*)aNotification
{
    //save data
    //GameExit();
    //if(HasOpenFeintInit())
    //{
    //[OpenFeint shutdown];
    //_openfeint_init = false;
    //}
    EndGame();
}

#ifdef DEBUG_MEMORY_WARNING
- (void) applicationDidReceiveMemoryWarning:(UIApplication*)application
{
    //show a warning dialog
}
#endif
-(void) iOS_ShowWebPage:(NSString*) url isoffline:(BOOL) offline
{
    [_pine_view_controller iOS_ShowWebPage:url isoffline:offline];
}
- (void) InitDisplay
{
    
    _pine_view_controller = [PineViewController alloc];
    
    CGRect rect = [[UIScreen mainScreen] bounds];
    CGRect windowRect = [[UIScreen mainScreen] applicationFrame];
    
#if USE_NEW_SYSTEM_VIEW_IOS_7_8
    _opgenGLESViewController = [[OpenGLESViewController alloc] init];
    
    float correctW, correctH;
    if (UIInterfaceOrientationIsLandscape([[UIApplication sharedApplication] statusBarOrientation]))
    {
        correctW = windowRect.size.width>windowRect.size.height?windowRect.size.width:windowRect.size.height;
        correctH = windowRect.size.height<windowRect.size.width?windowRect.size.height:windowRect.size.width;
        
    }
    else
    {
        correctW = windowRect.size.width<windowRect.size.height?windowRect.size.width:windowRect.size.height;
        correctH = windowRect.size.height>windowRect.size.width?windowRect.size.height:windowRect.size.width;
    }
    windowRect.size.width = correctW;
    windowRect.size.height = correctH;
    NSLog(@"windowRect %f %f ",correctW,correctH);
    
#else
    UIDevice *myDevice = [UIDevice currentDevice] ;
    [myDevice beginGeneratingDeviceOrientationNotifications];
    UIDeviceOrientation deviceOrientation = myDevice.orientation;
    BOOL isCurrentlyLandscapeView = UIDeviceOrientationIsLandscape(deviceOrientation);
    [myDevice endGeneratingDeviceOrientationNotifications];
    float tmp = rect.size.width;
    
    if(isCurrentlyLandscapeView){
        
        rect.size.width = rect.size.height> rect.size.width?rect.size.height:rect.size.width;
        rect.size.height = rect.size.width!=tmp? tmp:rect.size.height;
        printf("if :%f :%f\n", rect.size.width, rect.size.height);
    }else{
        rect.size.width = rect.size.height< rect.size.width?rect.size.height:rect.size.width;
        rect.size.height = rect.size.width!=tmp? tmp:rect.size.height;
        printf("else :%f :%f\n", rect.size.width, rect.size.height);
    }
#endif
    bool i6Later = false;
    float scale_factor = 2.0f;
    
    if((rect.size.width == 375.000000&& rect.size.height ==667.000000)||(rect.size.width == 414.000000&& rect.size.height ==736.000000)
       ||(rect.size.width == 667.000000&& rect.size.height == 375.000000)||(rect.size.width == 736.000000&& rect.size.height == 414.000000)
       ||(rect.size.width == 320.000000&& rect.size.height == 568.000000)||(rect.size.width == 568.000000&& rect.size.height == 320.000000)
       )
    {
        i6Later = true;
        if((rect.size.width == 375.000000&& rect.size.height == 667.000000)
           || (rect.size.width == 667.000000&& rect.size.height == 375.000000))
        {
            scale_factor = 2.0f;
        }
        if((rect.size.width == 414.000000&& rect.size.height ==736.000000)
           || (rect.size.width == 736.000000&& rect.size.height ==414.000000))
        {
            scale_factor = 3.0f;
        }
        printf("dkfjkdfjkdjfdkfkd fdkf dfjkdjfdkfkdjfefkdkfkdf \n");
    }
    
    CGRect rt =  CGRectMake(0,0,IOS8_MASTER_W/2,IOS8_MASTER_H/2);
    
#if USE_NEW_SYSTEM_VIEW_IOS_7_8
    if (rect.size.width > rect.size.height)
    {
        rt = CGRectMake(0,0,IOS8_MASTER_H/2,IOS8_MASTER_W/2);
    }
#else
#endif
    
    window = [[UIWindow alloc] initWithFrame:rect];
#if USE_NEW_SYSTEM_VIEW_IOS_7_8
    [window setRootViewController:_opgenGLESViewController];
#endif
    window.backgroundColor = [UIColor blackColor];
    
    CGRect fromRect = rt;
    CGRect viewRect = rect;
    
    CGSize scales = CGSizeMake(viewRect.size.width/fromRect.size.width,
                               viewRect.size.height/fromRect.size.height);
    
    CGAffineTransform transform = CGAffineTransformMakeScale(scales.width,
                                                             scales.height);
    
    
    //[window sizeThatFits:rect.size];
    //Create the OpenGL ES view and add it to the window
    if(i6Later)
    {
        glView = [[EAGLView alloc] initGL:rt];
        [glView initWithFrame:rt];
        //NSLog(@"dkfjkjf jkj kfdjfkdfj rect %f %f ",rt.size.width,rt.size.height);
    }
    else
    {
        glView = [[EAGLView alloc] initGL:windowRect];
        [glView initWithFrame:windowRect];
        
    }
    glView.multipleTouchEnabled = YES;
    
    //add OpenGL ES view to window
    if(i6Later)
    {
        window.contentScaleFactor = scale_factor;
        glView.contentScaleFactor = scale_factor;
        glView.transform = transform;
        glView.center = CGPointMake(rect.size.width/2,rect.size.height/2);
    }
#if USE_NEW_SYSTEM_VIEW_IOS_7_8
    _opgenGLESViewController.view = glView;
    [window addSubview:_opgenGLESViewController.view];
#else
    [window addSubview:glView];
#endif
    //Show the window
    [window makeKeyAndVisible];
}

#if CAPTURE_SCREENSHOT
extern "C" bool ExitsFile(const char *file_name);
-(void) capture_screenshot
{
    UIGraphicsBeginImageContextWithOptions(glView.bounds.size, NO, 1.0f);
    
    [glView drawViewHierarchyInRect:glView.bounds afterScreenUpdates:NO];
    
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    NSData*theImageData=UIImagePNGRepresentation(image); //you can use PNG too
    NSString* fileToSaveTo = [NSString stringWithFormat:@"%s" , "pine_capture.png"];
    
    //NSString* fileURL = [NSString stringWithFormat:@"%s" , url];
    NSArray* path = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES);
    NSString* documentsDirectory = [path objectAtIndex:0];
    
    //[theImageData writeToFile:@"pine_capture.png" atomically:YES];
    [theImageData writeToFile:[NSString stringWithFormat:@"%@/%@",documentsDirectory,fileToSaveTo] atomically:NO];
    while(!ExitsFile("pine_capture.png")){
        ;
        printf("\nCheck Exits file");
        sleep(1);
    }
    printf("\nCAPTURE complete");
    
}
#endif

#ifdef USE_VIDEO
- (void) MoviePlayerInit:(NSString*)movie_name
{
    MoviePlayer* mp = [[MoviePlayer alloc] initWithFile:movie_name];
    [MoviePlayer setSharedInstance:mp];
}
#endif

#ifndef USE_CUSTOM_KEYBOARD

+ (PineGameDelegate*) sharedInstance
{
    return g_PineGameInstance;
}

- (void) TextInputInit:(TextInputInitParams*)params
{
    TextInput* ti = [[TextInput alloc] initWithTextBuffer:(char*)params->textBuff WithSize:params->buffSize AtX:params->x Y:params->y Width:params->w Height:params->h];
    [TextInput setSharedInstance:ti];
}

#endif

- (void) MediaPickerInit:(MediaPickerParams*)params
{
    //printf("MediaPickerInit \n");
    MediaPicker* mi = [[MediaPicker alloc] init];
    
    [MediaPicker setSharedInstance: mi];
    [mi showMediaPicker];
}

//////////////////////////////////////////////////////////////////////////
- (void) dealloc
{
    [glView release];
    [window release];
    [super dealloc];
}

- (void) CleanTouch
{
    [glView ClearTouch];
}


- (void) GCLeaderBoard:(NSObject*)params
{
    /*
     if(![GameCenterManager getSharedInstance])
     {
     GameCenterManager* gc = [[GameCenterManager alloc] init];
     [GameCenterManager setSharedInstance: gc];
     }
     [[GameCenterManager getSharedInstance] initGCBoard];
     */
    [[GameCenterManager getSharedInstance] showLeaderboard];
}

- (void) GCAchievementBoard:(NSObject*)params
{
    /*
     if(![GameCenterManager getSharedInstance])
     {
     GameCenterManager* gc = [[GameCenterManager alloc] init];
     [GameCenterManager setSharedInstance: gc];
     }
     [[GameCenterManager getSharedInstance] initGCBoard];
     */
    [[GameCenterManager getSharedInstance] showAchievementsboard];
}



//In app Purchase




//#endif
#if ADD_PICK_IMAGE
///-(void) SaveImageToPath(UIImage* image, NSString *file,int width_target,int hieght_target)
//{

///}
-(void) InitTakePictureDelegate
{
    
    _PickState =  PICK_STATE_TAKE_PICTURE;
    bool init = false;
    if(_image_pick == nil)
    {
        _image_pick = [[UIImagePickerController alloc] init];
        init = true;
    }
    _image_pick.delegate = self;
    _image_pick.sourceType = UIImagePickerControllerSourceTypeCamera;
    [_image_pick setShowsCameraControls:NO];
    _image_pick.view.hidden = NO;
    [glView removeFromSuperview];
    [window addSubview:_image_pick.view];
    [_image_pick.view addSubview:glView];
    
    
    
}
-(void)takeAPictureSaveToPath
{
    [_image_pick takePicture];
    
    /*[_image_pick dismissModalViewControllerAnimated:YES];
     [glView removeFromSuperview];
     _image_pick.view.hidden =  YES;
     [_image_pick.view removeFromSuperview];
     [window addSubview:glView];
     */
}
-(void) InitPickImage
{
    _PickState =  PICK_STATE_CHOICE_PICTURE;
    if(_image_pick == nil)
    {
        _image_pick = [[UIImagePickerController alloc] init];
    }
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) {
        UIPopoverController *popover = [[UIPopoverController alloc] initWithContentViewController:_image_pick];
        _image_pick.delegate = self;
        _image_pick.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
        
        [popover presentPopoverFromRect:CGRectMake(0, k_SCREEN_HEIGHT,1,1) inView:glView permittedArrowDirections:UIPopoverArrowDirectionDown animated:YES];
        
    }
    else
    {
        
        _image_pick.delegate = self;
        _image_pick.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
        [window addSubview:_image_pick.view];
    }
}

-(void) imagePickerController:(UIImagePickerController*)picker
        didFinishPickingImage:(UIImage *)image
                  editingInfo:(NSDictionary *)editingInfo
{
    
    [picker dismissModalViewControllerAnimated:YES];
    [glView removeFromSuperview];
    _image_pick.view.hidden =  YES;
    [_image_pick.view removeFromSuperview];
    [window addSubview:glView];
    
}
-(void) imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
    [picker dismissModalViewControllerAnimated:YES];
    [glView removeFromSuperview];
    _image_pick.view.hidden =  YES;
    [_image_pick.view removeFromSuperview];
    [window addSubview:glView];
    //exit(0);
}
- (void) PushRemoteNotification:(NSObject*)params
{
    
    DevicePushRemoteNotification("f270c51076723179cca57e93b85c4935927f219d3791bccc700a1232ba77530c","Hello world!");
    
}

#endif
#if ENABLE_SERVER_PUSH_NOTIFICATION
- (void)application:(UIApplication *)app didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    NSString *str =
    [NSString stringWithFormat:@"\n Device token %@",deviceToken];
    printf("\nbondle path = %s",GetBundlePath());
    //[[PineGameDelegate sharedInstance] performSelectorOnMainThread:@selector(PushRemoteNotification:) withObject:nil waitUntilDone:YES];
    NSLog(str);
    ///385ee17eb8de4c0306fe42979cc67ba2dbd332c812e3dcbd07d858aa69df6146
}

- (void)application:(UIApplication *)app didFailToRegisterForRemoteNotificationsWithError:(NSError *)err
{
    NSString *str = [NSString stringWithFormat: @"Error: %@", err];
    NSLog(str);
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    
    for (id key in userInfo) {
        NSLog(@"key: %@, value: %@", key, [userInfo objectForKey:key]);
    }
    
}
#endif

- (void) Thread_LoadImageToPngFile:(NSArray*)params
{
    const char *url = [(NSString*)[params objectAtIndex:0] UTF8String];
    const char *file_name = [(NSString*)[params objectAtIndex:1] UTF8String];
    printf("url = %s _file_name = %s",url,file_name);
    //const char *file_name = params
    //create URL load
    
    NSString *_url = [NSString stringWithUTF8String:url];
    
    //load data image from URL (can be jpg)
    UIImage *image = [[UIImage alloc] initWithData:[NSData dataWithContentsOfURL:[NSURL URLWithString:_url ]]];;
    
    //convert imagedata to PNG
    NSData * _imgdata = UIImagePNGRepresentation(image);
    [image release];
    
    //create path to save file
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    
    NSString* fname = [[NSString alloc] initWithUTF8String: file_name];
    NSString *appfilename = [documentsDirectory stringByAppendingPathComponent:fname];
    
    //save file to document
    [_imgdata writeToFile:appfilename  atomically:NO];
    [_imgdata release];
    
}

- (void) LoadIAP
{
    AppPurchase = [InAppPurchase alloc];
    if([AppPurchase CanPayment])
    {
        printf("\nYou can buy item");
        InitInAppPurchase();
        
    }

}


#pragma mark - Odata Util Methods

-(void)getHeaderForProxy: (const char*)_id onjectConext:(ObjectContext *)proxy
{
    NSString *str1, *str2, *str3, *str4;
    NSData *encode;
    
    str1 = [self getSecurityString:_id];
    [proxy addHeader:@"Authorization" headerValue:[[NSString alloc] initWithFormat:@"Basic %@", str1]];
    
    str1 = [NSString stringWithFormat:@"%s", CGame::_this->_device.getDeviceAgent()];
    encode = [self encryptString:str1 withKey:MY_SERCET_PASSWORD ];
    str2 = [self base64forData:encode];
    [proxy addHeader:@"X-Tag" headerValue:str2];
    
    str1 = @"";
    str1 = [str1 stringByAppendingFormat:@"sd=%d", DEVICE().DisplayProperties.ColorDepth];
    str1 = [str1 stringByAppendingFormat:@"&sr=%dx%d", (int)DEVICE().ScreenSize.W, (int)DEVICE().ScreenSize.H];
    str1 = [str1 stringByAppendingFormat:@"&vp=%dx%d", (int)DEVICE().ScreenSize.W, (int)DEVICE().ScreenSize.H];
    
    str1 = [str1 stringByAppendingFormat:@"&cid=%@", [[[NSClassFromString(@"ASIdentifierManager") sharedManager] advertisingIdentifier] UUIDString]];
    
    str2 = [self base64Encode:str1];
    [proxy addHeader:@"X-Params" headerValue:str2];
    
    NSDictionary* infoDictionary = [[NSBundle mainBundle] infoDictionary];
    str3 = infoDictionary[@"CFBundleVersion"];
    encode = [self encryptString:str3 withKey:MY_SERCET_PASSWORD ];
    str4 = [self base64forData:encode];
    //str4 = [self base64Encode:str3];
    [proxy addHeader:@"X-Version" headerValue:str4];
    
    [str1 release];
    [str2 release];
    [encode release];
}

- (NSData*) encryptString:(NSString*)plaintext withKey:(NSString*)key {
    return [[plaintext dataUsingEncoding:NSUTF8StringEncoding] AES256EncryptWithKey:key];
    
}

- (NSString *)base64Encode:(NSString *)plainText
{
    NSData *plainTextData = [plainText dataUsingEncoding:NSUTF8StringEncoding];
    //NSString *base64String = [plainTextData base64EncodedString];
    NSString *base64String = [self base64forData:plainTextData];
    return base64String;
}

- (NSString*)base64forData:(NSData*)theData {
    
    char encodingTable[64] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
        'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f',
        'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
        'w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/' };
    
    const unsigned char	*bytes = (const unsigned char	*)[theData bytes];
    NSMutableString *result = [NSMutableString stringWithCapacity:[theData length]];
    unsigned long ixtext = 0;
    unsigned long lentext = [theData length];
    long ctremaining = 0;
    unsigned char inbuf[3], outbuf[4];
    unsigned short i = 0;
    unsigned short charsonline = 0, ctcopy = 0;
    unsigned long ix = 0;
    
    while( YES ) {
        ctremaining = lentext - ixtext;
        if( ctremaining <= 0 ) break;
        
        for( i = 0; i < 3; i++ ) {
            ix = ixtext + i;
            if( ix < lentext ) inbuf[i] = bytes[ix];
            else inbuf [i] = 0;
        }
        
        outbuf [0] = (inbuf [0] & 0xFC) >> 2;
        outbuf [1] = ((inbuf [0] & 0x03) << 4) | ((inbuf [1] & 0xF0) >> 4);
        outbuf [2] = ((inbuf [1] & 0x0F) << 2) | ((inbuf [2] & 0xC0) >> 6);
        outbuf [3] = inbuf [2] & 0x3F;
        ctcopy = 4;
        
        switch( ctremaining ) {
            case 1:
                ctcopy = 2;
                break;
            case 2:
                ctcopy = 3;
                break;
        }
        
        for( i = 0; i < ctcopy; i++ )
            [result appendFormat:@"%c", encodingTable[outbuf[i]]];
        
        for( i = ctcopy; i < 4; i++ )
            [result appendString:@"="];
        
        ixtext += 3;
        charsonline += 4;
        
    }
    
    return [NSString stringWithString:result];
    
}

-(NSString *)getSecurityString:(const char*)_id
{
    //NSLog(@"\n ID_str = %s",_id);
    NSString* ret = [NSString alloc];
    char* macAddressString= (char*)malloc(18);
    NSString* macAddress= [[NSString alloc] initWithFormat:@"%s", "0200000000"];
    NSString* NS_GC = [[NSString alloc] initWithUTF8String:_id];
    
    NSData *result = [[PineGameDelegate sharedInstance] encryptString:NS_GC withKey:MY_SERCET_PASSWORD ];
    
    
    NSString* newStr = [[PineGameDelegate sharedInstance] base64forData:result];
    
    
    ret = [NSString stringWithFormat:@"%@:%@", macAddress, newStr];
    
    ret = [[PineGameDelegate sharedInstance] base64Encode:ret];
    
    SAFE_DEL_ARRAY(macAddressString);
    [macAddress release];
    [NS_GC release];
    [result release];
    [newStr release];
    //NSLog(@"\n ID_str return = %@",ret);
    return ret;
}

#if ADD_TWITTER
#include "PineTwitter.h"
#endif
#if ADD_FACEBOOK
#include "PineFacebook.h"
#endif
#include "PineMacOSFunc.h"
@end

extern "C" bool isChartboostAvailable()
{
    return [[PineGameDelegate sharedInstance] chartboostAvailable];
    //[[PineGameDelegate sharedInstance] InitTakePicture];
    
}

extern "C" void InitTakePicture()
{
    [[PineGameDelegate sharedInstance] performSelectorOnMainThread:@selector(InitTakePictureDelegate) withObject:nil waitUntilDone:NO];
    //[[PineGameDelegate sharedInstance] InitTakePicture];
    
}
extern "C" void takeAPicture()
{
    [[PineGameDelegate sharedInstance] performSelectorOnMainThread:@selector(takeAPictureSaveToPath) withObject:nil waitUntilDone:NO];
    //[[PineGameDelegate sharedInstance] takeAPictureSaveToPath];
    
}

extern "C" void LoadImageToPngFile(const char* url,const char *file_name)
{
    NSArray* a = [[NSArray alloc] init];
    NSString* _url = [NSString stringWithFormat:@"%s",url];
    NSString* _file_name = [NSString stringWithFormat:@"%s",file_name];
    a = [a arrayByAddingObject:_url];
    a = [a arrayByAddingObject:_file_name];
    [[PineGameDelegate sharedInstance] Thread_LoadImageToPngFile:a];
    
}

extern "C" void	GoToReviewInItune()
{
    NSString *reviewURL = [APPIRATER_TPL_URL stringByReplacingOccurrencesOfString:@"APP_ID" withString:[NSString stringWithFormat:@"%d", APPLE_APP_ID]];
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:reviewURL]];
    
}

extern "C" void LoadInAppStore()
{
    [PineGameDelegate sharedInstance].AppPurchase = [InAppPurchase alloc];
    if([[PineGameDelegate sharedInstance].AppPurchase CanPayment])
    {
        printf("\nYou can buy item");
        InitInAppPurchase();
        
    }
}

extern "C" void RequestRegisterNotificationSetting()
{
    if ([UIApplication instanceMethodForSelector:@selector(registerUserNotificationSettings:)])
    {
        NSLog(@"\n has registerUserNotificationSettings");
        [[UIApplication sharedApplication] registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
    }
    else
    {
        NSLog(@"\n has notttt registerUserNotificationSettings");
        UIRemoteNotificationType myTypes = UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeSound;
        [[UIApplication sharedApplication] registerForRemoteNotificationTypes:myTypes];
    }
}


#if CAPTURE_SCREENSHOT
extern "C" void CaptureScreenshot()
{
    [[PineGameDelegate sharedInstance] capture_screenshot];
    
}
#endif

//quoc.nguyen
#include <sys/time.h>
extern "C" INT_TIME GetMilisecondOld()
{
    struct timeval cur_time;
    gettimeofday(&cur_time,0);
    return (cur_time.tv_sec*1000 + cur_time.tv_usec/1000);
}

