//
//  LLSMoreOperationController.h
//  LLSMoreOperationControllerDemo
//
//  Created by FingerIOSDEV on 16/12/28.
//  Copyright © 2016年 fingertop. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LLSMoreOperationController : UIViewController
@property(nonatomic, strong) UIColor *contentBackgroundColor UI_APPEARANCE_SELECTOR;
@property(nonatomic, strong) UIColor *contentSeparatorColor UI_APPEARANCE_SELECTOR;
@property(nonatomic, strong) UIColor *cancelButtonBackgroundColor UI_APPEARANCE_SELECTOR;
@property(nonatomic, strong) UIColor *cancelButtonTitleColor UI_APPEARANCE_SELECTOR;
@property(nonatomic, strong) UIColor *cancelButtonSeparatorColor UI_APPEARANCE_SELECTOR;
@property(nonatomic, strong) UIColor *itemBackgroundColor UI_APPEARANCE_SELECTOR;
@property(nonatomic, strong) UIColor *itemTitleColor UI_APPEARANCE_SELECTOR;
@property(nonatomic, strong) UIFont  *itemTitleFont UI_APPEARANCE_SELECTOR;
@property(nonatomic, strong) UIFont  *cancelButtonFont UI_APPEARANCE_SELECTOR;
@property(nonatomic, assign) CGFloat contentEdgeMargin UI_APPEARANCE_SELECTOR;
@property(nonatomic, assign) CGFloat contentMaximumWidth UI_APPEARANCE_SELECTOR;
@property(nonatomic, assign) CGFloat contentCornerRadius UI_APPEARANCE_SELECTOR;
@property(nonatomic, assign) CGFloat itemMarginTop UI_APPEARANCE_SELECTOR;
@property(nonatomic, assign) UIEdgeInsets topScrollViewInsets UI_APPEARANCE_SELECTOR;
@property(nonatomic, assign) UIEdgeInsets bottomScrollViewInsets UI_APPEARANCE_SELECTOR;
@property(nonatomic, assign) CGFloat cancelButtonHeight UI_APPEARANCE_SELECTOR;
@property(nonatomic, assign) CGFloat cancelButtonMarginTop UI_APPEARANCE_SELECTOR;

/// 代理
//@property(nonatomic, weak) id<QMUIMoreOperationDelegate> delegate;

/// 获取当前当前所有的item
@property(nonatomic, copy, readonly) NSArray *items;

/// 获取取消按钮
@property(nonatomic, strong, readonly) UIButton *cancelButton;

/// 更多操作面板是否正在显示
@property(nonatomic, assign, getter=isShowing, readonly) BOOL showing;
@property(nonatomic, assign, getter=isAnimating, readonly) BOOL animating;

/// 弹出更多操作面板，一般在init完并且设置好item之后就调用这个接口来显示面板
- (void)showFromBottom;
/// 与showFromBottom相反
- (void)hideToBottom;



@end


@interface LLSMoreOperationController (UIAppearance)

+ (instancetype)appearance;

@end

