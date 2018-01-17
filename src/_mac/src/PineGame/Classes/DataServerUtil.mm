//
//  DataServerUtil.m
//  PineEntertainment
//
//  Created by Elita Thai on 8/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "PineGameDelegate.h"
#import "TapDefenseContext.h"

#include <string.h>

#include "CGame.h"
#include "Os_Functions.h"
#include "iPhoneGameUtils.h"
int server_ret = -1;
BOOL dispatch_queue_is_empty(dispatch_queue_t queue)
{
    dispatch_group_t group = dispatch_group_create();
    
    dispatch_group_enter(group);
    dispatch_async(queue, ^{
        dispatch_group_leave(group);
    });
    
    int64_t maxWaitTime = 0.00000005 * NSEC_PER_SEC;
    BOOL isReady = dispatch_group_wait(group, maxWaitTime) == 0;
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), ^{
        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        dispatch_release(group);
    });
    
    return isReady;
}

extern "C" bool checkServerRealIsAble()
{
    //sprintf(URL_SERVER, "%s", URL_SERVER_REAL);
    //return true;
    bool ret =  false;
    @try {
        dispatch_queue_t dispatchQueue = dispatch_queue_create("checkServerRealIsAble.Pine.Entertainment.com", 0);   //ie. your made-up queue name
        dispatch_queue_is_empty(dispatchQueue);
        NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
        
        [request setCachePolicy:NSURLRequestReloadIgnoringCacheData];
        [request setHTTPShouldHandleCookies:NO];
        [request setTimeoutInterval:16];
        [request setHTTPMethod:@"GET"];
        
        [request setURL:[NSURL URLWithString:[NSString stringWithUTF8String:URL_SERVER_REAL_TEST]] ];
        
        NSHTTPURLResponse* response = nil;
        NSError *error = nil;
        // make the connection to the web
        NSData *returnData = [NSURLConnection sendSynchronousRequest:request returningResponse:&response error:&error];
        
        if ([response statusCode] == 200 || [response statusCode] == 304)
        {
            sprintf(URL_SERVER, "%s", URL_SERVER_REAL);
            ret = true;
        }
        
        NSLog(@"\n status code 1 = %ld \n - setURL = %s", (long)[response statusCode],URL_SERVER_REAL_TEST);
        
        [request release];
        [returnData release];
    }
    @catch (NSException *exception) {
        ret = false;
        NSLog(@"\n exception = %@ \n", exception);
    }
    @finally {
        
    }
    
    return ret;
}

extern "C" bool SetServerTime(Pine_Date_Time &time)
{
   time.setNullDay();
   
   if (!Device::IsNetworkAvailable())
   {
       return false;
   }
   
   bool ret = true;
   
   TapDefenseContext *proxy = [[TapDefenseContext alloc] initWithUri:[NSString stringWithUTF8String: URL_SERVER]  credential:nil];
   [proxy setParseData:ParseDataType::JSON_Parser_Type];
    [proxy setTimeOutInterval:30];
    //printf("\n GAME()->_serverThread._idStringLogin = %s",GAME()->_serverThread._idStringLogin);
   [[PineGameDelegate sharedInstance] getHeaderForProxy:GAME()->_serverThread._idStringLogin onjectConext:proxy];
    @try
    {
       DataServiceQuery *query = [proxy serverinfos];
       QueryOperationResponse *response = [query execute];
       if (response)
       {
           ODataObject_ServerInfo *save = [[response getResult] objectAtIndex:0];
           
           NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
           [dateFormat setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
           [dateFormat setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss"];
           
           NSString *stringFromDate = [dateFormat stringFromDate:[save getPstNow]];
           [dateFormat release];
           
           int year = [[stringFromDate substringWithRange:NSMakeRange(0, 4)] intValue];
           int month = [[stringFromDate substringWithRange:NSMakeRange(5, 2)] intValue];
           int day = [[stringFromDate substringWithRange:NSMakeRange(8, 2)] intValue];
           int hour = [[stringFromDate substringWithRange:NSMakeRange(11, 2)] intValue];
           int minute = [[stringFromDate substringWithRange:NSMakeRange(14, 2)] intValue];
           int second = [[stringFromDate substringWithRange:NSMakeRange(17, 2)] intValue];
           
           [stringFromDate release];
           //[dateFormat release];
           time.setDateByRealDate(year, month, day, hour, minute, second);
           
           [save release];
       }
       else
       {
           ret = false;
       }
    }
    @catch (DataServiceRequestException * e)
    {
        NSLog(@"0 exception:: 1%@: %@",[e name], [e debugDescription]);
        ret = false;
    }
    @catch(ODataServiceException *e)
    {
        NSLog(@"1 exception:: %ld ", [e getStatusCode]);
        ret = false;
    }
    @catch (NSException * e)
    {
        NSLog(@"all exception:: %@: %@", [e name], [e reason]);
        ret = false;
    }
   return ret;
}

extern "C" int GetServerSaveStatus()
{
    printf("\n get server status");
    TDGame*game = (TDGame*)(GAME()->_current_game);
    dispatch_queue_t dispatchQueue = dispatch_queue_create("GetServerSaveStatus.Pine.Entertainment.com", 0);   //ie. your made-up queue name
    dispatch_queue_is_empty(dispatchQueue);
    int ret = CServerThread::enumServerStatus::SERVER_STATUS_ERROR;
    
    bool isNullIdSave = false;
    if (strcmp(game->_user.GetUserID(), "user_id") == 0 )
    {
        isNullIdSave = true;
    }
    
    if (!isNullIdSave && strcmp(game->_user.GetUserID(), GAME()->_serverThread._idStringLogin) != 0)
    {
        ret = CServerThread::enumServerStatus::SERVER_STATUS_SWAP_ACCOUNT;
    }
    
    TapDefenseContext *proxy = [[TapDefenseContext alloc] initWithUri:[NSString stringWithUTF8String: URL_SERVER]  credential:nil];
    [proxy setParseData:ParseDataType::JSON_Parser_Type];
    [proxy setTimeOutInterval:10];
    [[PineGameDelegate sharedInstance] getHeaderForProxy:GAME()->_serverThread._idStringLogin onjectConext:proxy];
    
    ODataObject_SaveGame *saveGame = nil;
    
    @try
    {
        DataServiceQuery *query = [proxy savegames];
        QueryOperationResponse *response = [query execute:[NSString stringWithFormat:@"('%s')", GAME()->_serverThread._idStringLogin]];
        
        if (response)
        {
            
            saveGame = [[response getResult] objectAtIndex:0];
            long size = 0;
            size = [[saveGame getData] length];
            char buffer_temp[SAVE_MAX_BUFFER];
            [[saveGame getData] getBytes:buffer_temp length:size];
            int battle_current = GAME()->GetInt32At(buffer_temp, SAVE_FORMAT_BATTLE_CURRENT);
            
            if (battle_current > game->_battle_current)
            {
                ret = CServerThread::enumServerStatus::SERVER_STATUS_SERVER_IS_NEW;
            }
            else
            {
                if(battle_current == game->_battle_current)
                {
                    INT_TIME coin = GAME()->GetInt64At(buffer_temp, SAVE_FORMAT_QUEST_NUM_COIN_COLLECTED);
                    if(coin > game->_user._quest_num_coin_collected)
                    {
                        ret = CServerThread::enumServerStatus::SERVER_STATUS_SERVER_IS_NEW;
                    }
                    else
                    {
                        ret = CServerThread::enumServerStatus::SERVER_STATUS_LOCAL_IS_NEW;
                    }
                    
                }
                else
                {
                    ret = CServerThread::enumServerStatus::SERVER_STATUS_LOCAL_IS_NEW;
                }
            }
        }
    }
    @catch (DataServiceRequestException * e)
    {
        NSLog(@"0 exception:: 1%@: %@",[e name], [e debugDescription]);
        if ([[e getResponse] getStatusCode] == 404)
        {
            ret = CServerThread::enumServerStatus::SERVER_STATUS_NO_RECORD;
        }
    }
    @catch(ODataServiceException *e)
    {
        NSLog(@"1 exception:: %ld ", [e getStatusCode]);
    }
    @catch (NSException * e)
    {
        NSLog(@"all exception:: %@: %@", [e name], [e reason]);
    }
    
    printf("\n check server STATUS = %d ", ret);
    
    //proccess status
    dispatch_queue_t dispatchQueue2 = dispatch_queue_create("GetServerSaveStatus2.Pine.Entertainment.com", 0);   //ie. your made-up queue name
    dispatch_queue_is_empty(dispatchQueue2);
    @try
    {
        if(ret == CServerThread::enumServerStatus::SERVER_STATUS_NO_RECORD)
        {
            //game->_user.UserDefault();
            char name[128];
            char userid[128];
            sprintf(userid, "%s", GAME()->_serverThread._idStringLogin);
            sprintf(name, "%s", GAME()->_serverThread._userNameLogin);
            game->_user.SetUserID(userid);
            game->_user.SetUserName(name);
            game->_user.UserDataSave();
            
            //create accout
            ODataObject_SaveGame *save = [[ODataObject_SaveGame alloc] init];
            [save setID:[NSString stringWithUTF8String:GAME()->_serverThread._idStringLogin]];
            [save setUserName:[NSString stringWithUTF8String:game->_user.GetName()]];

            NSData *data = [[NSData alloc] initWithBytes:game->_user._buffer length:MAX_SAVE_BUFFER_CACHE];
            [save setData:data];
            [proxy addToSaveGames:save];
            [proxy saveChanges];
            [save release];
            [data release];
        }
        else if (ret == CServerThread::enumServerStatus::SERVER_STATUS_LOCAL_IS_NEW)
        {
            char name[128];
            char userid[128];
            sprintf(userid, "%s", GAME()->_serverThread._idStringLogin);
            sprintf(name, "%s", GAME()->_serverThread._userNameLogin);
            game->_user.SetUserID(userid);
            game->_user.SetUserName(name);
            game->_user.UserDataSave();
            
            //syn save to server
            
            [saveGame setUserName:[NSString stringWithUTF8String:game->_user.GetName()]];

            NSData *data = [[NSData alloc] initWithBytes:game->_user._buffer length:MAX_SAVE_BUFFER_CACHE];
            [saveGame setData:data];
            [proxy updateObject:saveGame];
            [proxy saveChanges];
            [data release];
        }
        else if (ret == CServerThread::enumServerStatus::SERVER_STATUS_SWAP_ACCOUNT
                 || ret == CServerThread::enumServerStatus::SERVER_STATUS_SERVER_IS_NEW)
        {
            long size = 0;
            size = [[saveGame getData] length];
            char buffer_temp[SAVE_MAX_BUFFER];
            [[saveGame getData] getBytes:buffer_temp length:size];
            int battle_current = GAME()->GetInt32At(buffer_temp, SAVE_FORMAT_BATTLE_CURRENT);
            printf("\n server battle_current = %d",battle_current);
            [[saveGame getData] getBytes:game->_user._buffer length:size];
            battle_current = GAME()->GetInt32At(game->_user._buffer, SAVE_FORMAT_BATTLE_CURRENT);
            printf("\n 11 server battle_current = %d",battle_current);
        }
        
        if(saveGame != nil)
        {
            [saveGame release];
        }
        
        [proxy release];
    }
    @catch (DataServiceRequestException * e)
    {
        NSLog(@"0 exception:: 1%@: %@",[e name], [e debugDescription]);
        ret = CServerThread::enumServerStatus::SERVER_STATUS_ERROR;
    }
    @catch(ODataServiceException *e)
    {
        NSLog(@"1 exception:: %ld ", [e getStatusCode]);
        ret = CServerThread::enumServerStatus::SERVER_STATUS_ERROR;
    }
    @catch (NSException * e)
    {
        NSLog(@"all exception:: %@: %@", [e name], [e reason]);
        ret = CServerThread::enumServerStatus::SERVER_STATUS_ERROR;
    }
    
    return ret;
}

extern "C" void SynSaveToServer()
{
    TDGame*game = (TDGame*)(GAME()->_current_game);
    dispatch_queue_t dispatchQueue = dispatch_queue_create("SynSaveToServer.Pine.Entertainment.com", 0);   //ie. your made-up queue name
    dispatch_queue_is_empty(dispatchQueue);
    bool noAccount = false;
    @try
    {
        TapDefenseContext *proxy = [[TapDefenseContext alloc] initWithUri:[NSString stringWithUTF8String: URL_SERVER]  credential:nil];
        [proxy setParseData:ParseDataType::JSON_Parser_Type];
        [proxy setTimeOutInterval:10];
        [[PineGameDelegate sharedInstance] getHeaderForProxy:GAME()->_serverThread._idStringLogin onjectConext:proxy];
        DataServiceQuery *query = [proxy savegames];
        NSString *userId = [[NSString alloc] initWithFormat:@"('%s')", GAME()->_serverThread._idStringLogin];
        QueryOperationResponse *response = [query execute:userId];
        [userId release];
        if (response)
        {
            if ([[response getResult] count] > 0)
            {
                ODataObject_SaveGame *save = [[response getResult] objectAtIndex:0];
                
                //[save setID:[NSString stringWithUTF8String:GAME()->_serverThread._idStringLogin]];
                [save setUserName:[NSString stringWithUTF8String:game->_user.GetName()]];
 
                NSData *data = [[NSData alloc] initWithBytes:game->_user._buffer length:MAX_SAVE_BUFFER_CACHE];
                [save setData:data];
                [proxy updateObject:save];
                [proxy saveChanges];
                [save release];
                [data release];
            }
            else
            {
                noAccount = true;
            }
        }
        [proxy release];
    }
    @catch (DataServiceRequestException * e)
    {
        NSLog(@"0 exception:: 2%@: %@",[e name], [e debugDescription]);
        if ([[e getResponse] getStatusCode] == 404)
        {
            noAccount = true;
        }
    }
    @catch(ODataServiceException *e)
    {
        NSLog(@"1 exception:: %ld ", [e getStatusCode]);
    }
    @catch (NSException * e)
    {
        NSLog(@"all exception:: %@: %@", [e name], [e reason]);
    }
    
    if (!noAccount)
    {
        return;
    }
    
    @try
    {
        TapDefenseContext *proxy = [[TapDefenseContext alloc] initWithUri:[NSString stringWithUTF8String: URL_SERVER]  credential:nil];
        [proxy setParseData:ParseDataType::JSON_Parser_Type];
        [proxy setTimeOutInterval:10];
        [[PineGameDelegate sharedInstance] getHeaderForProxy:GAME()->_serverThread._idStringLogin onjectConext:proxy];
        
        ODataObject_SaveGame *save = [[ODataObject_SaveGame alloc] init];
        
        [save setID:[NSString stringWithUTF8String:GAME()->_serverThread._idStringLogin]];
        [save setUserName:[NSString stringWithUTF8String:game->_user.GetName()]];

        NSData *data = [[NSData alloc] initWithBytes:game->_user._buffer length:MAX_SAVE_BUFFER_CACHE];
        [save setData:data];
        [proxy addToSaveGames:save];
        [proxy saveChanges];
        [save release];
        [data release];
        
        [proxy release];
    }
    @catch (DataServiceRequestException * e)
    {
        NSLog(@"0 exception:: 3%@: %@",[e name], [e debugDescription]);
    }
    @catch(ODataServiceException *e)
    {
        NSLog(@"1 exception:: %ld ", [e getStatusCode]);
    }
    @catch (NSException * e)
    {
        NSLog(@"all exception:: %@: %@", [e name], [e reason]);
    }
}

extern "C" bool SynSaveFromServer()
{
    TDGame*game = (TDGame*)(GAME()->_current_game);
    dispatch_queue_t dispatchQueue = dispatch_queue_create("SynSaveFromServer.Pine.Entertainment.com", 0);   //ie. your made-up queue name
    dispatch_queue_is_empty(dispatchQueue);
    bool ret = false;
    @try
    {
        TapDefenseContext *proxy = [[TapDefenseContext alloc] initWithUri:[NSString stringWithUTF8String: URL_SERVER]  credential:nil];
        [proxy setParseData:ParseDataType::JSON_Parser_Type];
        [proxy setTimeOutInterval:10];
        [[PineGameDelegate sharedInstance] getHeaderForProxy:GAME()->_serverThread._idStringLogin onjectConext:proxy];
        DataServiceQuery *query = [proxy savegames];
        NSString *userId = [[NSString alloc] initWithFormat:@"('%s')", GAME()->_serverThread._idStringLogin];
        QueryOperationResponse *response = [query execute:userId];
        [userId release];
        if (response)
        {
            //printf("\n save from server [[response getResult] count] = %d",[[response getResult] count]);
            if ([[response getResult] count] > 0)
            {
                ODataObject_SaveGame *save = [[response getResult] objectAtIndex:0];
                
                long size = 0;
                size = [[save getData] length];
                [[save getData] getBytes:game->_user._buffer length:size];
                /*INT_TIME coin = GAME()->GetInt64At(game->_user._buffer, SAVE_FORMAT_COIN);
                int gem = GAME()->GetInt32At(game->_user._buffer, SAVE_FORMAT_GEM);
                printf("\n save from server coin = %lld,coin = %d",coin,gem);
                char buff[size];
                [[save getData] getBytes:buff length:size];
                coin = GAME()->GetInt64At(buff, SAVE_FORMAT_COIN);
                gem = GAME()->GetInt32At(buff, SAVE_FORMAT_GEM);
                printf("\n buff temp save from server coin = %lld,coin = %d",coin,gem);*/
                [save release];
                ret = true;
            }
        }
        [proxy release];
    }
    @catch (DataServiceRequestException * e)
    {
        NSLog(@"0 exception:: 4%@: %@",[e name], [e debugDescription]);
    }
    @catch(ODataServiceException *e)
    {
        NSLog(@"1 exception:: %ld ", [e getStatusCode]);
    }
    @catch (NSException * e)
    {
        NSLog(@"all exception:: %@: %@", [e name], [e reason]);
    }
    @finally
    {
        
        
    }
    return ret;
}

extern "C" bool GetInvitedId(char *invitedId)
{
    bool ret = true;
    
    if (GAME()->_serverThread._idStringLogin[0] == '\0' || !GAME()->_serverThread._isInitGC)
    {
        return false;
    }
    
    @try
    {
        TapDefenseContext *proxy = [[TapDefenseContext alloc] initWithUri:[NSString stringWithUTF8String: URL_SERVER]  credential:nil];
        [proxy setParseData:ParseDataType::JSON_Parser_Type];
        [proxy setTimeOutInterval:10];
        
        [[PineGameDelegate sharedInstance] getHeaderForProxy:GAME()->_serverThread._idStringLogin onjectConext:proxy];
        
        DataServiceQuery *query = [proxy invitations];
        QueryOperationResponse *response = [query execute];
        
        if (response)
        {
            ODataObject_Invitation *invitaion = [[response getResult] objectAtIndex:0];
            
            sprintf(invitedId, "%s", [[invitaion getInvitationId] UTF8String]);
            
            [invitaion release];
            
            ret = true;
        }
        
        [proxy release];
    }
    @catch (DataServiceRequestException * e)
    {
        NSLog(@"0 exception:: 2%@: %@",[e name], [e debugDescription]);
        ret = false;
    }
    @catch(ODataServiceException *e)
    {
        NSLog(@"1 exception:: %ld ", [e getStatusCode]);
        ret = false;
    }
    @catch (NSException * e)
    {
        NSLog(@"all exception:: %@: %@", [e name], [e reason]);
        ret = false;
    }
    
    return ret;
}
extern "C" bool GetInvitionFriends()
{
    bool ret = true;
    TDGame*game = (TDGame*)(GAME()->_current_game);
    if (GAME()->_serverThread._idStringLogin[0] == '\0' || !GAME()->_serverThread._isInitGC)
    {
        return false;
    }
    
    @try
    {
        TapDefenseContext *proxy = [[TapDefenseContext alloc] initWithUri:[NSString stringWithUTF8String: URL_SERVER]  credential:nil];
        [proxy setParseData:ParseDataType::JSON_Parser_Type];
        [proxy setTimeOutInterval:10];
        
        [[PineGameDelegate sharedInstance] getHeaderForProxy:GAME()->_serverThread._idStringLogin onjectConext:proxy];
        
        DataServiceQuery *query = [proxy invitedfriends];
        QueryOperationResponse *response = [query execute];
        
        if (response)
        {
            game->_user._invitation_num = (int)[[response getResult] count];
            printf("\n get  _user._invitation_num = %d",game->_user._invitation_num);
            if(game->_user._invitation_num > 3)
            {
                game->_user._invitation_num = 3;
            }
            /*for (int i = 0; i < [[response getResult] count]; i++)
            {
                ODataObject_InvitedFriend *inviteFriend = [[response getResult] objectAtIndex:i];
                
                [inviteFriend release];
            }*/
            ret = true;
        }
        
        [proxy release];
    }
    @catch (DataServiceRequestException * e)
    {
        NSLog(@"0 exception:: 2%@: %@",[e name], [e debugDescription]);
        ret = false;
    }
    @catch(ODataServiceException *e)
    {
        NSLog(@"1 exception:: %ld ", [e getStatusCode]);
        ret = false;
    }
    @catch (NSException * e)
    {
        NSLog(@"all exception:: %@: %@", [e name], [e reason]);
        ret = false;
    }
    
    return ret;
}

extern "C" int InputInvitetionCode(char *inviteCode)
{
    int ret = 0;
    
    if (GAME()->_serverThread._idStringLogin[0] == '\0' || !GAME()->_serverThread._isInitGC)
    {
        return 0;
    }
    
    TapDefenseContext *proxy = [[TapDefenseContext alloc] initWithUri:[NSString stringWithUTF8String: URL_SERVER]  credential:nil];
    [proxy setParseData:ParseDataType::JSON_Parser_Type];
    [proxy setTimeOutInterval:10];
    [[PineGameDelegate sharedInstance] getHeaderForProxy:GAME()->_serverThread._idStringLogin onjectConext:proxy];
    
    //proccess status
    @try
    {
        ODataObject_Invitation *invation = [[ODataObject_Invitation alloc] init];
        
        [invation setInvitedBy:[NSString stringWithFormat:@"%s", inviteCode]];
        
        [proxy addToInvitations:invation];
        [proxy saveChanges];
        [invation release];
        
        [proxy release];
        
        ret = 1;
    }
    @catch (DataServiceRequestException * e)
    {
        NSLog(@"0 exception:: 1%@: %@",[e name], [e debugDescription]);
        ret = 0;
    }
    @catch(ODataServiceException *e)
    {
        NSInteger errorCode = [e getStatusCode];
        if (errorCode == 400 || errorCode == 500)
        {
            ret = 2;
        }
        NSLog(@"1 exception:: %ld ", (long)[e getStatusCode]);
        
    }
    @catch (NSException * e)
    {
        NSLog(@"all exception:: %@: %@", [e name], [e reason]);
        ret = 0;
    }
    return ret;
}
