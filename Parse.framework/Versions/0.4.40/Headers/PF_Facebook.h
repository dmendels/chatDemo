/*
 * Copyright 2010 Facebook
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "PF_FBLoginDialog.h"
#import "PF_FBRequest.h"

@protocol PF_FBSessionDelegate;

/**
 * Main Facebook interface for interacting with the Facebook developer API.
 * Provides methods to log in and log out a user, make requests using the REST
 * and Graph APIs, and start user interface interactions (such as
 * pop-ups promoting for credentials, permissions, stream posts, etc.)
 */
@interface PF_Facebook : NSObject<PF_FBLoginDialogDelegate>{
  NSString* _accessToken;
  NSDate* _expirationDate;
  id<PF_FBSessionDelegate> _sessionDelegate;
  PF_FBRequest* _request;
  PF_FBDialog* _loginDialog;
  PF_FBDialog* _fbDialog;
  NSString* _appId;
  NSString* _localAppId;
  NSArray* _permissions;
}

@property(nonatomic, copy) NSString* accessToken;
@property(nonatomic, copy) NSDate* expirationDate;
@property(nonatomic, assign) id<PF_FBSessionDelegate> sessionDelegate;
@property(nonatomic, copy) NSString* localAppId;

- (id)initWithAppId:(NSString *)appId
        andDelegate:(id<PF_FBSessionDelegate>)delegate;

- (void)authorize:(NSArray *)permissions;

- (void)authorize:(NSArray *)permissions
       localAppId:(NSString *)localAppId;

- (BOOL)handleOpenURL:(NSURL *)url;

- (void)logout:(id<PF_FBSessionDelegate>)delegate;

- (PF_FBRequest*)requestWithParams:(NSMutableDictionary *)params
                    andDelegate:(id <PF_FBRequestDelegate>)delegate;

- (PF_FBRequest*)requestWithMethodName:(NSString *)methodName
                          andParams:(NSMutableDictionary *)params
                      andHttpMethod:(NSString *)httpMethod
                        andDelegate:(id <PF_FBRequestDelegate>)delegate;

- (PF_FBRequest*)requestWithGraphPath:(NSString *)graphPath
                       andDelegate:(id <PF_FBRequestDelegate>)delegate;

- (PF_FBRequest*)requestWithGraphPath:(NSString *)graphPath
                         andParams:(NSMutableDictionary *)params
                       andDelegate:(id <PF_FBRequestDelegate>)delegate;

- (PF_FBRequest*)requestWithGraphPath:(NSString *)graphPath
                         andParams:(NSMutableDictionary *)params
                     andHttpMethod:(NSString *)httpMethod
                       andDelegate:(id <PF_FBRequestDelegate>)delegate;

- (void)dialog:(NSString *)action
   andDelegate:(id<PF_FBDialogDelegate>)delegate;

- (void)dialog:(NSString *)action
     andParams:(NSMutableDictionary *)params
   andDelegate:(id <PF_FBDialogDelegate>)delegate;

- (BOOL)isSessionValid;

@end

////////////////////////////////////////////////////////////////////////////////

/**
 * Your application should implement this delegate to receive session callbacks.
 */
@protocol PF_FBSessionDelegate <NSObject>

@optional

/**
 * Called when the user successfully logged in.
 */
- (void)fbDidLogin;

/**
 * Called when the user dismissed the dialog without logging in.
 */
- (void)fbDidNotLogin:(BOOL)cancelled;

/**
 * Called when the user logged out.
 */
- (void)fbDidLogout;

@end
