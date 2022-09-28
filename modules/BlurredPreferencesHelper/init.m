#import <UIKit/UIKit.h>
#import <libhooker/libhooker.h>

static void (*original_UIViewController_viewDidLoad)(UIViewController *self, SEL selector);
static void custom_UIViewController_viewDidLoad(UIViewController * self, SEL selector) {
    original_UIViewController_viewDidLoad(self, selector);
    if ([self isKindOfClass:NSClassFromString(@"PSSplitViewController")]) {
        // if I set clearColor or alpha value as 0.0f, touch event doesn't work correctly - why?
        [self.view setBackgroundColor:[UIColor.blackColor colorWithAlphaComponent:0.001f]];
    } else {
        [self.view setBackgroundColor:UIColor.clearColor];
    }
}

static void (*original_UIViewController_viewWillAppear)(UIViewController *self, SEL selector, BOOL animated);
static void custom_UIViewController_viewWillAppear(UIViewController * self, SEL selector, BOOL animated) {
    original_UIViewController_viewWillAppear(self, selector, animated);
    [self.transitionCoordinator animateAlongsideTransition:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        [self.view setAlpha:1.0f];
    } completion:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        
    }];
}

static void (*original_UIViewController_viewWillDisappear)(UIViewController *self, SEL selector, BOOL animated);
static void custom_UIViewController_viewWillDisappear(UIViewController * self, SEL selector, BOOL animated) {
    original_UIViewController_viewWillDisappear(self, selector, animated);
   
    [self.transitionCoordinator animateAlongsideTransition:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        [self.view setAlpha:0.0f];
    } completion:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        
    }];
}

static void (*original_UITableView_setBackgroundColor)(UITableView *self, SEL selector, UIColor *backgroundColor);
static void custom_UITableView_setBackgroundColor(UITableView *self, SEL selector, UIColor *backgroundColor) {
    NSLog(@"%@, %@", self, backgroundColor);
    original_UITableView_setBackgroundColor(self, selector, UIColor.clearColor);
}

static UIColor * (*original_UITableView_backgroundColor)(UITableView *self, SEL selector);
static UIColor * custom_UITableView_backgroundColor(UITableView *self, SEL selector) {
    return UIColor.clearColor;
}

static void (*original_UITableViewCell_setBackgroundColor)(UITableViewCell *self, SEL selector, UIColor *backgroundColor);
static void custom_UITableViewCell_setBackgroundColor(UITableViewCell *self, SEL selector, UIColor *backgroundColor) {
    original_UITableViewCell_setBackgroundColor(self, selector, [backgroundColor colorWithAlphaComponent:0.3f]);
}

static UIColor * (*original_UITableViewCell_backgroundColor)(UITableViewCell *self, SEL selector);
static UIColor * custom_UITableViewCell_backgroundColor(UITableViewCell *self, SEL selector) {
    return UIColor.clearColor;
}

__attribute__((constructor)) static void init() {
    LBHookMessage(UIViewController.class, @selector(viewDidLoad), &custom_UIViewController_viewDidLoad, &original_UIViewController_viewDidLoad);
    LBHookMessage(UIViewController.class, @selector(viewWillAppear:), &custom_UIViewController_viewWillAppear, &original_UIViewController_viewWillAppear);
    LBHookMessage(UIViewController.class, @selector(viewWillDisappear:), &custom_UIViewController_viewWillDisappear, &original_UIViewController_viewWillDisappear);
    LBHookMessage(UITableView.class, @selector(setBackgroundColor:), &custom_UITableView_setBackgroundColor, &original_UITableView_setBackgroundColor);
    // LBHookMessage(UITableView.class, @selector(backgroundColor), &custom_UITableView_backgroundColor, &original_UITableView_backgroundColor);
    LBHookMessage(UITableViewCell.class, @selector(setBackgroundColor:), &custom_UITableViewCell_setBackgroundColor, &original_UITableViewCell_setBackgroundColor);
    // LBHookMessage(UITableViewCell.class, @selector(backgroundColor), &custom_UITableViewCell_backgroundColor, &original_UITableViewCell_backgroundColor);
}
