//
//  LLSButton.h
//  LLSMoreOperationControllerDemo
//
//  Created by FingerIOSDEV on 16/12/28.
//  Copyright © 2016年 fingertop. All rights reserved.
//

#import <UIKit/UIKit.h>


// 图片位置，默认为LLSButtonImagePositionLeft
typedef enum {
    LLSButtonImagePositionTop,
    LLSButtonImagePositionLeft,
    LLSButtonImagePositionBottom,
    LLSButtonImagePostionRight,
} LLSButtonImagePostion;

typedef enum {
    LLSGhostButtonColorBlue,
    LLSGhostButtonColorRed,
    LLSGhostButtonColorGreen,
    LLSGhostButtonColorGray,
    LLSGhostButtonColorWhite,
}LLSGhostButtonColor;

typedef enum {
    LLSFillButtonColorBlue,
    LLSFillButtonColorRed,
    LLSFillButtonColorGreen,
    LLSFillButtonColorGray,
    LLSFillButtonColorWhite,
} LLSFillButtonColor;



@interface LLSButton : UIButton
/**
 * 让按钮的文字颜色自动跟随tintColor调整（系统默认titleColor是不跟随的）<br/>
 * 默认为NO
 */
@property(nonatomic, assign) BOOL adjustsTitleTintColorAutomatically;

/**
 * 让按钮的图片颜色自动跟随tintColor调整（系统默认image是需要更改renderingMode才可以达到这种效果）<br/>
 * 默认为NO
 */
@property(nonatomic, assign) BOOL adjustsImageTintColorAutomatically;

/**
 * 是否自动调整highlighted时的按钮样式，默认为YES。<br/>
 * 当值为YES时，按钮highlighted时会改变自身的alpha属性为<b>ButtonHighlightedAlpha</b>
 */
@property(nonatomic, assign) BOOL adjustsButtonWhenHighlighted;

/**
 * 是否自动调整disabled时的按钮样式，默认为YES。<br/>
 * 当值为YES时，按钮disabled时会改变自身的alpha属性为<b>ButtonDisabledAlpha</b>
 */
@property(nonatomic, assign) BOOL adjustsButtonWhenDisabled;

/**
 * 设置按钮点击时的背景色，默认为nil。
 * @warning 不支持带透明度的背景颜色。当设置<i>highlightedBackgroundColor</i>时，会强制把<i>adjustsButtonWhenHighlighted</i>设为NO，避免两者效果冲突。
 * @see adjustsButtonWhenHighlighted
 */
@property(nonatomic, strong) UIColor *highlightedBackgroundColor;

/**
 * 设置按钮点击时的边框颜色，默认为nil。
 * @warning 当设置<i>highlightedBorderColor</i>时，会强制把<i>adjustsButtonWhenHighlighted</i>设为NO，避免两者效果冲突。
 * @see adjustsButtonWhenHighlighted
 */
@property(nonatomic, strong) UIColor *highlightedBorderColor;

/**
 * 设置按钮里图标和文字的相对位置，默认为QMUIButtonImagePositionLeft<br/>
 * 可配合imageEdgeInsets、titleEdgeInsets、contentHorizontalAlignment、contentVerticalAlignment使用
 */
@property(nonatomic, assign) LLSButtonImagePostion imagePosition;
@end

/**
 *  支持显示下划线的按钮，可用于需要链接的场景。下划线默认和按钮宽度一样，可通过 `underlineInsets` 调整。
 */
@interface QMUILinkButton : LLSButton

/// 控制下划线隐藏或显示，默认为NO，也即显示下划线
@property(nonatomic, assign) BOOL underlineHidden;

/// 设置下划线的宽度，默认为 1
@property(nonatomic, assign) CGFloat underlineWidth;

/// 控制下划线颜色，若设置为nil，则使用当前按钮的titleColor的颜色作为下划线的颜色。默认为 nil。
@property(nonatomic, strong) UIColor *underlineColor;

/// 下划线的位置是基于 titleLabel 的位置来计算的，默认x、width均和titleLabel一致，而可以通过这个属性来调整下划线的偏移值。默认为UIEdgeInsetsZero。
@property(nonatomic, assign) UIEdgeInsets underlineInsets;

@end

/**
 *  用于 `QMUIGhostButton.cornerRadius` 属性，当 `cornerRadius` 为 `QMUIGhostButtonCornerRadiusAdjustsBounds` 时，`QMUIGhostButton` 会在高度变化时自动调整 `cornerRadius`，使其始终保持为高度的 1/2。
 */
extern const CGFloat QMUIGhostButtonCornerRadiusAdjustsBounds;

/**
 *  “幽灵”按钮，也即背景透明、带圆角边框的按钮
 *
 *  可通过 `QMUIGhostButtonColor` 设置几种预设的颜色，也可以用 `ghostColor` 设置自定义颜色。
 *
 *  @warning 默认情况下，`ghostColor` 只会修改文字和边框的颜色，如果需要让 image 也跟随 `ghostColor` 的颜色，则可将 `adjustsImageWithGhostColor` 设为 `YES`
 */
@interface QMUIGhostButton : LLSButton

@property(nonatomic, strong) UIColor *ghostColor;    // 默认为 UIColorBlue
@property(nonatomic, assign) CGFloat borderWidth UI_APPEARANCE_SELECTOR;    // 默认为 1pt
@property(nonatomic, assign) CGFloat cornerRadius UI_APPEARANCE_SELECTOR;   // 默认为 QMUIGhostButtonCornerRadiusAdjustsBounds，也即固定保持按钮高度的一半。

/**
 *  控制按钮里面的图片是否也要跟随 `ghostColor` 一起变化，默认为 `NO`
 */
@property(nonatomic, assign) BOOL adjustsImageWithGhostColor UI_APPEARANCE_SELECTOR;

- (instancetype)initWithGhostType:(LLSGhostButtonColor)ghostType;
- (instancetype)initWithGhostColor:(UIColor *)ghostColor;

@end


/**
 *  用于 `QMUIFillButton.cornerRadius` 属性，当 `cornerRadius` 为 `QMUIFillButtonCornerRadiusAdjustsBounds` 时，`QMUIFillButton` 会在高度变化时自动调整 `cornerRadius`，使其始终保持为高度的 1/2。
 */
extern const CGFloat QMUIFillButtonCornerRadiusAdjustsBounds;

/**
 *  QMUIFillButton
 *  实心填充颜色的按钮，支持预定义的几个色值
 */
@interface QMUIFillButton : LLSButton

@property(nonatomic, strong) UIColor *fillColor; // 默认为 UIColorBlue
@property(nonatomic, strong) UIColor *titleTextColor; // 默认为 UIColorWhite
@property(nonatomic, assign) CGFloat cornerRadius UI_APPEARANCE_SELECTOR;// 默认为 QMUIFillButtonCornerRadiusAdjustsBounds，也即固定保持按钮高度的一半。

/**
 *  控制按钮里面的图片是否也要跟随 `titleTextColor` 一起变化，默认为 `NO`
 */
@property(nonatomic, assign) BOOL adjustsImageWithTitleTextColor UI_APPEARANCE_SELECTOR;

- (instancetype)initWithFillType:(LLSFillButtonColor)fillType;
- (instancetype)initWithFillType:(LLSFillButtonColor)fillType frame:(CGRect)frame;
- (instancetype)initWithFillColor:(UIColor *)fillColor titleTextColor:(UIColor *)textColor;
- (instancetype)initWithFillColor:(UIColor *)fillColor titleTextColor:(UIColor *)textColor frame:(CGRect)frame;

@end

