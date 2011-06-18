//
//  AsyncContinuationsAppDelegate.h
//  AsyncContinuations
//
//  Created by Igor Evsukov on 18.06.11.
//  Copyright 2011 Igor Evsukov. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    
    UIActivityIndicatorView *requestActivityIndicatorView;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet UIActivityIndicatorView *requestActivityIndicatorView;

- (void)startRequest:(id)sender;

@end

