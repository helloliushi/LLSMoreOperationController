//
//  ViewController.m
//  LLSMoreOperationControllerDemo
//
//  Created by FingerIOSDEV on 16/12/28.
//  Copyright © 2016年 fingertop. All rights reserved.
//

#import "ViewController.h"
@interface ViewController ()

@property (nonatomic, strong) UITableView *tableView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    
    UILabel *testLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 50, 0, 0)];
    testLabel.backgroundColor = [UIColor redColor];
    testLabel.text = @"我们都有都有";
    testLabel.font = [UIFont systemFontOfSize:20];
    testLabel.textColor = [UIColor blackColor];
    
  CGSize seze = [testLabel sizeThatFits:CGSizeMake(20, 20)];//会计算出最优的 size 但是不会改变 自己的 size，个人认为这个就是 label 自适应大小有用别的没什么用
    
    NSLog(@"testLabel sizeThatFits frame = %@", NSStringFromCGRect(testLabel.frame));
    NSLog(@"best size = %@",NSStringFromCGSize([testLabel sizeThatFits:CGSizeMake(20, 20)]));
  //  [testLabel sizeToFit];//会计算出最优的 size 而且会改变自己的size
    NSLog(@"testLabel sizeToFit frame = %@",NSStringFromCGRect(testLabel.frame));
    [self.view  addSubview:testLabel];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



@end
