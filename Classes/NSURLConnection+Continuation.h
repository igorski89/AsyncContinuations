//
//  NSURLConnection+Continuation.h
//  AsyncContinuations
//
//  Created by Evsukov Igor on 18.06.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURLConnection (Continuation)

+ (void)sendRequest:(NSURLRequest*)request withResult:(void(^)(NSError *error,NSURLResponse *responce,NSData *responceData))result_block;

@end
