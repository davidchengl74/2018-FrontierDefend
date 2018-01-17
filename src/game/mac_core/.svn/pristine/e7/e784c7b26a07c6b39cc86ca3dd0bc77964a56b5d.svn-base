#if !_IN_APP_PURCHASE_H
#define _IN_APP_PURCHASE_H 1

#import <Foundation/NSObject.h>
#import <UIKit/UIKit.h>
#import <Foundation/NSURLConnection.h>
#import "CGame.h"
#import <StoreKit/StoreKit.h>
#define BOUNDLE_ID   "dalton2.colorbox.com"

#define kInAppPurchaseManagerProductsFetchedNotification @"kInAppPurchaseManagerProductsFetchedNotification"
#define kInAppPurchaseManagerTransactionFailedNotification @"kInAppPurchaseManagerTransactionFailedNotification"
#define kInAppPurchaseManagerTransactionSucceededNotification @"kInAppPurchaseManagerTransactionSucceededNotification"
#define kInAppPurchaseProUpgradeProductId @"dalton2.colorbox.com"
#define TIME_OUT_REQUEST 5000


@interface InAppPurchase : NSObject <SKProductsRequestDelegate, SKPaymentTransactionObserver>
{
    SKProduct *proUpgradeProduct;
    SKProductsRequest *productsRequest;
    SKProductsRequest *productInformations;
    int _time_request;
}
// public methods
- (void)loadStore;
- (BOOL)canMakePurchases;
- (void)purchaseProUpgrade;
- (void)Restore;
- (bool)CanPayment;
- (void) PurchaseProduct:(NSString *)productID;
- (void) RefeshStore;

-(void) SetTimeOut:(int) time;
-(void) UpdateTimeOut:(int) dt;
-(int) GetTimeOut;

@end

#endif
