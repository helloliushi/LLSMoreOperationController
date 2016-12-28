//
//  LLSButton.m
//  LLSMoreOperationControllerDemo
//
//  Created by FingerIOSDEV on 16/12/28.
//  Copyright © 2016年 fingertop. All rights reserved.
//

#import "LLSButton.h"


#define UIColorMake(r, g, b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1]
#define ButtonTintColor UIColorMake(43, 133, 208)

@interface LLSButton ()
@property (nonatomic, strong) CALayer *hightlightedBackgroundLayer;
@property (nonatomic, strong) UIColor *originBorderColor;

@end


@implementation LLSButton

- (instancetype) initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        self.adjustsImageTintColorAutomatically = NO;
        self.adjustsTitleTintColorAutomatically = NO;
        self.tintColor = ButtonTintColor;
        if (!self.adjustsTitleTintColorAutomatically) {
            [self setTitleColor:ButtonTintColor forState:UIControlStateNormal];
        }
        // 默认接管highlighted和disabled的表现，去掉系统默认的表现
        self.adjustsImageWhenHighlighted = NO;
        self.adjustsImageWhenDisabled = NO;
        self.adjustsButtonWhenHighlighted = YES;
        self.adjustsButtonWhenDisabled = YES;
        
        // iOS7以后的button，sizeToFit后默认会自带一个上下的contentInsets，为了保证按钮大小即为内容大小，这里直接去掉，改为一个最小的值。
        // 不能设为0，否则无效；也不能设置为小数点，否则无法像素对齐
        self.contentEdgeInsets = UIEdgeInsetsMake(1, 0, 1, 0);
        
        // 图片默认在按钮左边，与系统UIButton保持一致
        self.imagePosition = LLSButtonImagePositionLeft;

    }
    return  self;
}

- (CGSize)sizeThatFits:(CGSize)size {
    if (CGSizeEqualToSize(self.bounds.size,size)) {
        size = CGSizeMake(CGFLOAT_MAX, CGFLOAT_MAX);
    }
    
    CGSize resultSize = CGSizeZero;
    CGSize contentLimitSize = CGSizeMake(size.width - UIEdgeInsetsGetHorizontalValue(self.contentEdgeInsets), size.height - UIEdgeInsetsGetVerticalValue(self.contentEdgeInsets));
    switch (self.imagePosition) {
        case LLSButtonImagePositionTop:
        case QMUIButtonImagePositionBottom: {
            // 图片和文字上下排版时，宽度以文字或图片的最大宽度为最终宽度
            CGFloat imageLimitWidth = contentLimitSize.width - UIEdgeInsetsGetHorizontalValue(self.imageEdgeInsets);
            CGSize imageSize = [self.imageView sizeThatFits:CGSizeMake(imageLimitWidth, CGFLOAT_MAX)];// 假设图片高度必定完整显示
            
            CGSize titleLimitSize = CGSizeMake(contentLimitSize.width - UIEdgeInsetsGetHorizontalValue(self.titleEdgeInsets), contentLimitSize.height - UIEdgeInsetsGetVerticalValue(self.imageEdgeInsets) - imageSize.height - UIEdgeInsetsGetVerticalValue(self.titleEdgeInsets));
            CGSize titleSize = [self.titleLabel sizeThatFits:titleLimitSize];
            titleSize.height = fminf(titleSize.height, titleLimitSize.height);
            
            resultSize.width = UIEdgeInsetsGetHorizontalValue(self.contentEdgeInsets);
            resultSize.width += fmaxf(UIEdgeInsetsGetHorizontalValue(self.imageEdgeInsets) + imageSize.width, UIEdgeInsetsGetHorizontalValue(self.titleEdgeInsets) + titleSize.width);
            resultSize.height = UIEdgeInsetsGetVerticalValue(self.contentEdgeInsets) + UIEdgeInsetsGetVerticalValue(self.imageEdgeInsets) + imageSize.height + UIEdgeInsetsGetVerticalValue(self.titleEdgeInsets) + titleSize.height;
        }
            break;
            
        case QMUIButtonImagePositionLeft:
        case QMUIButtonImagePositionRight: {
            if (self.imagePosition == QMUIButtonImagePositionLeft && self.titleLabel.numberOfLines == 1) {
                
                // QMUIButtonImagePositionLeft使用系统默认布局
                resultSize = [super sizeThatFits:size];
                
            } else {
                // 图片和文字水平排版时，高度以文字或图片的最大高度为最终高度
                // titleLabel为多行时，系统的sizeThatFits计算结果依然为单行的，所以当QMUIButtonImagePositionLeft并且titleLabel多行的情况下，使用自己计算的结果
                
                CGFloat imageLimitHeight = contentLimitSize.height - UIEdgeInsetsGetVerticalValue(self.imageEdgeInsets);
                CGSize imageSize = [self.imageView sizeThatFits:CGSizeMake(CGFLOAT_MAX, imageLimitHeight)];// 假设图片宽度必定完整显示，高度不超过按钮内容
                
                CGSize titleLimitSize = CGSizeMake(contentLimitSize.width - UIEdgeInsetsGetHorizontalValue(self.titleEdgeInsets) - imageSize.width - UIEdgeInsetsGetHorizontalValue(self.imageEdgeInsets), contentLimitSize.height - UIEdgeInsetsGetVerticalValue(self.titleEdgeInsets));
                CGSize titleSize = [self.titleLabel sizeThatFits:titleLimitSize];
                titleSize.height = fminf(titleSize.height, titleLimitSize.height);
                
                resultSize.width = UIEdgeInsetsGetHorizontalValue(self.contentEdgeInsets) + UIEdgeInsetsGetHorizontalValue(self.imageEdgeInsets) + imageSize.width + UIEdgeInsetsGetHorizontalValue(self.titleEdgeInsets) + titleSize.width;
                resultSize.height = UIEdgeInsetsGetVerticalValue(self.contentEdgeInsets);
                resultSize.height += fmaxf(UIEdgeInsetsGetVerticalValue(self.imageEdgeInsets) + imageSize.height, UIEdgeInsetsGetVerticalValue(self.titleEdgeInsets) + titleSize.height);
            }
        }
            break;
    }
    return resultSize;

}


@end
