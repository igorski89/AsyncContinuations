//
//  NSURLConnection+Continuation.m
//  AsyncContinuations
//
//  Created by Evsukov Igor on 18.06.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "NSURLConnection+Continuation.h"

@implementation NSURLConnection (Continuation)

+ (void)sendRequest:(NSURLRequest*)request withResult:(void(^)(NSError *error,NSURLResponse *responce,NSData *responceData))result_block {    
    dispatch_queue_t original_queue = dispatch_get_current_queue();
    dispatch_retain(original_queue);
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        
        NSURLResponse *responce = nil;
        NSError *error = nil;
        
        NSData *responceData = [NSURLConnection sendSynchronousRequest:request 
                                                     returningResponse:&responce
                                                                 error:&error];
        
        dispatch_sync(original_queue, ^{ 
            result_block(error,responce,responceData);
        });
        dispatch_release(original_queue);
    });
}

@end
