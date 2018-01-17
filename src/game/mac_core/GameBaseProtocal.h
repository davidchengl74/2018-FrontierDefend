#ifndef _GameBaseProtocal_H_
#define _GameBaseProtocal_H_

#import <FirebaseAnalytics/FIRApp.h>
#import <FirebaseAuth/FIRAuth.h>
#import <FirebaseAuth/FIRFacebookAuthProvider.h>


FIRAuth *_handleFIRAuth;
extern "C" void OS_InitFireBase()
{
    // Use Firebase library to configure APIs
    [FIRApp configure];

}

extern "C" void OS_OpenSessionFireBase()
{
    _handleFIRAuth = [[FIRAuth auth]
              addAuthStateDidChangeListener:^(FIRAuth *_Nonnull auth, FIRUser *_Nullable user) {
                  NSLog(@"new sesion with auth %@ user %@",auth,user);
                  // ...
              }];
}
extern "C" void OS_CloseSessionFireBase()
{
    [[FIRAuth auth] removeAuthStateDidChangeListener:_handleFIRAuth];
}

extern "C" void OS_AuthFacebookWithFireBase()
{
    int slot = 0;
    FBSDKAccessToken *token = [SUCache itemForSlot:slot].token;
    if (token) {
        // We have a saved token, issue a request to make sure it's still valid.
        [FBSDKAccessToken setCurrentAccessToken:token];
        FIRAuthCredential *credential = [FIRFacebookAuthProvider
                                     credentialWithAccessToken:[FBSDKAccessToken currentAccessToken].tokenString];
                                [[FIRAuth auth] signInWithCredential:credential
                              completion:^(FIRUser *user, NSError *error) {
                                  if (error) {
                                      // ...
                                      return;
                                  }
                                  
                                  NSLog(@"User successfully signed in. Get user data from the FIRUser object");
                                  // ...
                              }];
    }
}

extern "C" void OS_SignOutFacebookFireBase()
{
    NSError *signOutError;
    BOOL status = [[FIRAuth auth] signOut:&signOutError];
    if (!status) {
        NSLog(@"Error signing out: %@", signOutError);
        return;
    }
}


#endif
