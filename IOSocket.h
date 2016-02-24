//
//  Socket.h
//  WhatMed
//
//  Created by Niklas on 12/01/15.
//  Copyright (c) 2015 Goldfish Productions. All rights reserved.
//

#import <Foundation/Foundation.h>

//#TODO: switch to https://github.com/socketio/socket.io-client-swift

// NSArray of these JSValue-valid objects:
typedef NSArray SIOParameterArray;
// --------------------
//        NSNull       
//       NSString      
//       NSNumber      
//     NSDictionary    
//       NSArray       
//        NSData
// --------------------

@interface IOSocket : NSObject

// Generators
+ (void)socketWithHost:(NSString *)hostURL params:(NSDictionary*)params response:(void(^)(IOSocket *socket))response;
+ (void)socketWithHost:(NSString *)hostURL params:(NSDictionary*)params reconnectAutomatically:(BOOL)reconnectAutomatically attemptLimit:(NSInteger)attempts withDelay:(NSTimeInterval)reconnectionDelay maximumDelay:(NSTimeInterval)maximumDelay timeout:(NSTimeInterval)timeout response:(void(^)(IOSocket *socket))response;
+ (void)socketWithHost:(NSString *)hostURL params:(NSDictionary*)params reconnectAutomatically:(BOOL)reconnectAutomatically attemptLimit:(NSInteger)attempts withDelay:(NSTimeInterval)reconnectionDelay maximumDelay:(NSTimeInterval)maximumDelay timeout:(NSTimeInterval)timeout withTransports:(NSArray *)transports response:(void(^)(IOSocket *socket))response;

// Event responders
@property (nonatomic, copy) void (^onConnect)();
@property (nonatomic, copy) void (^onConnectError)(NSDictionary *errorInfo);
@property (nonatomic, copy) void (^onDisconnect)();
@property (nonatomic, copy) void (^onError)(NSDictionary *errorInfo);

@property (nonatomic, copy) void (^onReconnect)(NSInteger numberOfAttempts);
@property (nonatomic, copy) void (^onReconnectionAttempt)(NSInteger numberOfAttempts);
@property (nonatomic, copy) void (^onReconnectionError)(NSDictionary *errorInfo);

- (void)on:(NSString *)event callback:(void (^)(SIOParameterArray *args))function;

// Emitters
- (void)emit:(NSString *)event;
- (void)emit:(NSString *)event args:(SIOParameterArray *)args;

- (void)close;

@end
