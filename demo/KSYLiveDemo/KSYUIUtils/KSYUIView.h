//
//  UIView+Frames.h
//  KSYGPUStreamerDemo
//
//  Created by 孙健 on 16/6/21.
//  Copyright © 2016年 ksyun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KSYNameSlider.h"

/**
 ksy自定义视图
 
 主要增加的功能如下:
 1. 增加更方便的视图尺寸查询属性
 2. 增加新建本SDK中常用控件的方法(按钮 滑块 开关等)
 3. 绑定事件响应的回调
 4. 增加简单的布局函数, 逐行添加任意数量的控件, 等大小,等距离放置
 
 演示SDK接口的各种视图都继承自此类
 */
@interface KSYUIView: UIView
#pragma mark - init 
- (id) initWithParent:(KSYUIView*)pView;

#pragma mark - geometry
@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGPoint origin;
@property (nonatomic, assign) CGSize size;

@property (nonatomic, assign) CGFloat gap;    // gap between btns (default 4)
@property (nonatomic, assign) CGFloat btnH;   // button's height (default 40)
// set by call [super layoutUI]
@property (nonatomic, assign) CGFloat winWdt; // default self.width - gap*2
@property (nonatomic, assign) CGFloat yPos;   // default gap*5

#pragma mark - UI elements layout
- (void) layoutUI;
// 均匀放置一行控件 (每次调用将控件追加到上一行控件之下,行内均匀排布)
- (void) putRow1:(UIView*)subV ;
- (void) putRow2:(UIView*)subV0
             and:(UIView*)subV1;
- (void) putRow3:(UIView*)subV0
             and:(UIView*)subV1
             and:(UIView*)subV2;
// 添加任意数量的视图数组
- (void) putRow:(NSArray *) subV;

// 不均匀的放置一行中lable + subview
//(lable 使用内容宽度, 剩余宽度全部分配给subview)
- (void) putLable:(UIView*)lbl
          andView:(UIView*)subV;
// slider和switch放一行
- (void) putSlider:(UIView*)sl
         andSwitch:(UIView*)sw;

#pragma mark - new and add UI elements
- (UITextField *) addTextField: (NSString*)text;
- (UISegmentedControl *)addSegCtrlWithItems: (NSArray *) items;
- (UILabel  *)addLable: (NSString*)title;
- (UIButton *)addButton:(NSString*)title;
- (UISwitch *)addSwitch:(BOOL) on;
- (UISlider *)addSliderFrom: (float) minV
                         To: (float) maxV
                       Init: (float) iniV;

- (KSYNameSlider *)addSliderName: (NSString*) name
                            From: (float) minV
                              To: (float) maxV
                            Init: (float) iniV;

// button with custom action
- (UIButton *)addButton:(NSString*)title
                 action:(SEL)action;
- (UISlider *)addSliderFrom: (float) minV
                         To: (float) maxV
                       Init: (float) iniV
                     action: (SEL)action;

#pragma mark - UI respond
//UIControlEventTouchUpInside
- (IBAction)onBtn:(id)sender;
//UIControlEventValueChanged
- (IBAction)onSwitch:(id)sender;
//UIControlEventValueChanged
- (IBAction)onSlider:(id)sender;
//UIControlEventValueChanged
- (IBAction)onSegCtrl:(id)sender;

@property(nonatomic, copy) void(^onBtnBlock)(id sender);
@property(nonatomic, copy) void(^onSwitchBlock)(id sender);
@property(nonatomic, copy) void(^onSliderBlock)(id sender);
@property(nonatomic, copy) void(^onSegCtrlBlock)(id sender);

// 获取设备的UUID
+ (NSString *) getUuid;
@end
