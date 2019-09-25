//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface ANSActivity : NSObject
{
    id <NSObject> _processInfoToken;
    NSString *_reason;
    unsigned int _backgroundTaskIdentifier;
    unsigned long long _options;
}

+ (id)beginActivityIfAvailable:(id)arg1 options:(unsigned long long)arg2;
+ (void)performActivity:(id)arg1 options:(unsigned long long)arg2 withBlock:(CDUnknownBlockType)arg3;
+ (id)beginActivity:(id)arg1 withOptions:(unsigned long long)arg2;
+ (id)beginActivity:(id)arg1 withOptions:(unsigned long long)arg2 expirationHandler:(CDUnknownBlockType)arg3;
@property(nonatomic) unsigned int backgroundTaskIdentifier; // @synthesize backgroundTaskIdentifier=_backgroundTaskIdentifier;
@property(readonly, nonatomic) NSString *reason; // @synthesize reason=_reason;
@property(readonly, nonatomic) unsigned long long options; // @synthesize options=_options;
@property(retain, nonatomic) id <NSObject> processInfoToken; // @synthesize processInfoToken=_processInfoToken;
- (void).cxx_destruct;
- (void)endAndInvalidateInternalActivity;
- (void)endAndInvalidateBackgroundTask;
- (BOOL)supportsBackgroundTasks;
- (id)sharedAppInstance;
- (void)end;
- (void)dealloc;
- (id)initWithProcessToken:(id)arg1 options:(unsigned long long)arg2 reason:(id)arg3 backgroundTaskIdentifier:(unsigned int)arg4;
- (unsigned int)beginBackgroundTaskWithName:(id)arg1 expirationHandler:(CDUnknownBlockType)arg2;

@end

