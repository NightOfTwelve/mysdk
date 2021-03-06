/**
 * Copyright 2015 leenjewel
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MySDKiOSDelegate_h
#define MySDKiOSDelegate_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define NSString2Char(ns,ds) (ns?[ns UTF8String]:ds)
#define NSString2CString(ns,ds) (ns?(std::string([ns UTF8String])):ds)
#define CString2NSString(cs) (cs.empty()?@"":[NSString stringWithCString:cs.c_str() encoding:NSUTF8StringEncoding])
#define Char2NSString(cs) (cs?[NSString stringWithCString:cs encoding:NSUTF8StringEncoding]:@"")


@protocol MySDKiOSCallbackDelegate <NSObject>

- (void) onApplySDK:(NSString*)sdkname Method:(NSString*)methodname Success:(NSString*)result;

- (void) onApplySDK:(NSString*)sdkname Method:(NSString*)methodname Cancel:(NSString*)result;

- (void) onApplySDK:(NSString*)sdkname Method:(NSString*)methodname Fail:(int)errorcode WithError:(NSString*)error AndResult:(NSString*)result;

- (void) onApplySDK:(NSString*)sdkname Pay:(NSString*)productid Order:(NSString*)orderid Fail:(int)errorcode WithError:(NSString*)error AndResult:(NSString*)result;

- (void) onApplySDK:(NSString*)sdkname Pay:(NSString*)productid Order:(NSString*)orderid Success:(NSString*)result;

@end




@protocol MySDKiOSDelegate <UIApplicationDelegate>

@optional
- (int) applySDKMethod:(NSString*)methodname AndReturnInt:(NSString*)params;

- (long) applySDKMethod:(NSString*)methodname AndReturnLong:(NSString*)params;

- (float) applySDKMethod:(NSString*)methodname AndReturnFloat:(NSString*)params;

- (double) applySDKMethod:(NSString*)methodname AndReturnDouble:(NSString*)params;

- (BOOL) applySDKMethod:(NSString*)methodname AndReturnBoolean:(NSString*)params;

- (NSString*) applySDKMethod:(NSString*)methodname AndReturnString:(NSString*)params;

- (void) applySDKMethod:(NSString*)methodname WithParams:(NSString*)params AndCallback:(id<MySDKiOSCallbackDelegate>)callback;

- (void) applySDKPay:(NSString*)productid Order:(NSString*)orderid WithParams:(NSString*)params AndCallback:(id<MySDKiOSCallbackDelegate>)callback;

@end

#endif /* MySDKiOSDelegate_h */
