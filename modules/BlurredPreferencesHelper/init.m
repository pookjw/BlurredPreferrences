#import <UIKit/UIKit.h>
#import <substrate.h>

@interface UIColor (BPH)
@property (class, readonly, nonatomic) UIColor *bph_clearColor;
@end

@implementation UIColor (BPH)

+ (UIColor *)bph_clearColor {
    // https://stackoverflow.com/a/11012121/17473716
    return [UIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:0.01f];
}

@end

void (*original_UIViewController_viewDidLoad)(UIViewController *self, SEL selector);
void custom_UIViewController_viewDidLoad(UIViewController * self, SEL selector) {
    original_UIViewController_viewDidLoad(self, selector);
    [self.view setBackgroundColor:UIColor.bph_clearColor];
}

void (*original_UIViewController_viewWillAppear)(UIViewController *self, SEL selector, BOOL animated);
void custom_UIViewController_viewWillAppear(UIViewController * self, SEL selector, BOOL animated) {
    original_UIViewController_viewWillAppear(self, selector, animated);
    [self.transitionCoordinator animateAlongsideTransition:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        [self.view setAlpha:1.0f];
    } completion:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        
    }];
}

void (*original_UIViewController_viewWillDisappear)(UIViewController *self, SEL selector, BOOL animated);
void custom_UIViewController_viewWillDisappear(UIViewController * self, SEL selector, BOOL animated) {
    original_UIViewController_viewWillDisappear(self, selector, animated);
   
    [self.transitionCoordinator animateAlongsideTransition:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        [self.view setAlpha:0.0f];
    } completion:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        
    }];
}

void (*original_UITableView_setBackgroundColor)(UITableView *self, SEL selector, UIColor *backgroundColor);
void custom_UITableView_setBackgroundColor(UITableView *self, SEL selector, UIColor *backgroundColor) {
    original_UITableView_setBackgroundColor(self, selector, UIColor.bph_clearColor);
}

void (*original_UITableViewCell_setBackgroundColor)(UITableViewCell *self, SEL selector, UIColor *backgroundColor);
void custom_UITableViewCell_setBackgroundColor(UITableViewCell *self, SEL selector, UIColor *backgroundColor) {
    original_UITableViewCell_setBackgroundColor(self, selector, [backgroundColor colorWithAlphaComponent:0.3f]);
}

__attribute__((constructor)) static void init() {
    @autoreleasepool {
        MSHookMessageEx(UIViewController.class, @selector(viewDidLoad), (IMP)&custom_UIViewController_viewDidLoad, (IMP *)&original_UIViewController_viewDidLoad);
        // MSHookMessageEx(UIViewController.class, @selector(viewWillAppear:), (IMP)&custom_UIViewController_viewWillAppear, (IMP *)&original_UIViewController_viewWillAppear);
        // MSHookMessageEx(UIViewController.class, @selector(viewWillDisappear:), (IMP)&custom_UIViewController_viewWillDisappear, (IMP *)&original_UIViewController_viewWillDisappear);
        MSHookMessageEx(UITableView.class, @selector(setBackgroundColor:), (IMP)&custom_UITableView_setBackgroundColor, (IMP *)&original_UITableView_setBackgroundColor);
        MSHookMessageEx(UITableViewCell.class, @selector(setBackgroundColor:), (IMP)&custom_UITableViewCell_setBackgroundColor, (IMP *)&original_UITableViewCell_setBackgroundColor);
    }
}
