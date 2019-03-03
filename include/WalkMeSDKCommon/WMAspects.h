//
//  WMAspects.h
//  WMAspects - A delightful, simple library for WMAspect oriented programming.
//
//  Copyright (c) 2014 Peter Steinberger. Licensed under the MIT license.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, WMAspectOptions) {
    WMAspectPositionAfter   = 0,            /// Called after the original implementation (default)
    WMAspectPositionInstead = 1,            /// Will replace the original implementation.
    WMAspectPositionBefore  = 2,            /// Called before the original implementation.
    
    WMAspectOptionAutomaticRemoval = 1 << 3 /// Will remove the hook after the first execution.
};

/// Opaque WMAspect Token that allows to deregister the hook.
@protocol WMAspectToken <NSObject>

/// Deregisters an WMAspect.
/// @return YES if deregistration is successful, otherwise NO.
- (BOOL)remove;

@end

/// The WMAspectInfo protocol is the first parameter of our block syntax.
@protocol WMAspectInfo <NSObject>

/// The instance that is currently hooked.
- (id)instance;

/// The original invocation of the hooked method.
- (NSInvocation *)originalInvocation;

/// All method arguments, boxed. This is lazily evaluated.
- (NSArray *)arguments;

@end

/**
 WMAspects uses Objective-C message forwarding to hook into messages. This will create some overhead. Don't add WMAspects to methods that are called a lot. WMAspects is meant for view/controller code that is not called a 1000 times per second.

 Adding WMAspects returns an opaque token which can be used to deregister again. All calls are thread safe.
 */
@interface NSObject (WMAspects)

/// Adds a block of code before/instead/after the current `selector` for a specific class.
///
/// @param block WMAspects replicates the type signature of the method being hooked.
/// The first parameter will be `id<WMAspectInfo>`, followed by all parameters of the method.
/// These parameters are optional and will be filled to match the block signature.
/// You can even use an empty block, or one that simple gets `id<WMAspectInfo>`.
///
/// @note Hooking static methods is not supported.
/// @return A token which allows to later deregister the WMAspect.
+ (id<WMAspectToken>)WMAspect_hookSelector:(SEL)selector
                           withOptions:(WMAspectOptions)options
                            usingBlock:(id)block
                                 error:(NSError **)error;

/// Adds a block of code before/instead/after the current `selector` for a specific instance.
- (id<WMAspectToken>)WMAspect_hookSelector:(SEL)selector
                           withOptions:(WMAspectOptions)options
                            usingBlock:(id)block
                                 error:(NSError **)error;

@end


typedef NS_ENUM(NSUInteger, WMAspectErrorCode) {
    WMAspectErrorSelectorBlacklisted,                   /// Selectors like release, retain, autorelease are blacklisted.
    WMAspectErrorDoesNotRespondToSelector,              /// Selector could not be found.
    WMAspectErrorSelectorDeallocPosition,               /// When hooking dealloc, only WMAspectPositionBefore is allowed.
    WMAspectErrorSelectorAlreadyHookedInClassHierarchy, /// Statically hooking the same method in subclasses is not allowed.
    WMAspectErrorFailedToAllocateClassPair,             /// The runtime failed creating a class pair.
    WMAspectErrorMissingBlockSignature,                 /// The block misses compile time signature info and can't be called.
    WMAspectErrorIncompatibleBlockSignature,            /// The block signature does not match the method or is too large.

    WMAspectErrorRemoveObjectAlreadyDeallocated = 100   /// (for removing) The object hooked is already deallocated.
};

extern NSString *const WMAspectErrorDomain;
