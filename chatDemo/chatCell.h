//
//  chatCell.h
//  chatDemo
//
//  Created by David Mendels on 4/14/12.
//  Copyright (c) 2012 Cognoscens. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface chatCell : UITableViewCell
{
    IBOutlet UILabel *userLabel;
	IBOutlet UITextView *textString;
	IBOutlet UILabel *timeLabel;
}

@property (nonatomic,strong) IBOutlet UILabel *userLabel;
@property (nonatomic,strong) IBOutlet UITextView *textString;
@property (nonatomic,strong) IBOutlet UILabel *timeLabel;

@end
