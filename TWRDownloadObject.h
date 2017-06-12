//
//  TWRDownloadObject.h
//  DownloadManager
//
//  Created by Michelangelo Chasseur on 26/07/14.
//  Copyright (c) 2014 Touchware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

typedef void(^TWRDownloadRemainingTimeBlock)(NSString* url, NSUInteger seconds);
typedef void(^TWRDownloadProgressBlock)(NSString* url, CGFloat progress);
typedef void(^TWRDownloadCancelationBlock)(NSString* url);
typedef void(^TWRDownloadErrorBlock)(NSString* url);
typedef void(^TWRDownloadCompletionBlock)(NSString* url);

@interface TWRDownloadObject : NSObject

@property (copy, nonatomic) TWRDownloadProgressBlock progressBlock;
@property (copy, nonatomic) TWRDownloadCancelationBlock cancelationBlock;
@property (copy, nonatomic) TWRDownloadErrorBlock errorBlock;
@property (copy, nonatomic) TWRDownloadCompletionBlock completionBlock;
@property (copy, nonatomic) TWRDownloadRemainingTimeBlock remainingTimeBlock;

@property (strong, nonatomic) NSURLSessionTask *downloadTask;
@property (copy, nonatomic) NSString *fileName;
@property (copy, nonatomic) NSString *friendlyName;
@property (copy, nonatomic) NSString *directoryName;
@property (copy, nonatomic) NSDate *startDate;
@property (atomic) NSUInteger startBytes;
@property (atomic) BOOL isRedownload;


- (instancetype)initWithDownloadTask:(NSURLSessionTask *)downloadTask
                       progressBlock:(TWRDownloadProgressBlock)progressBlock
                         cancelBlock:(TWRDownloadCancelationBlock)cancelBlock
                          errorBlock:(TWRDownloadErrorBlock)errorBlock
                       remainingTime:(TWRDownloadRemainingTimeBlock)remainingTimeBlock
                     completionBlock:(TWRDownloadCompletionBlock)completionBlock;

@end
