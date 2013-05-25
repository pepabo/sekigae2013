//
//  usage:
//     $ gcc sekigae.m -o sekigae -std=c99 -ObjC -framework Foundation
//     $ ./sekigae
//
#import <stdio.h>
#import <Foundation/Foundation.h>

@interface NSArray (randomized)
- (NSArray *) makeRandmizedArray;
@end

@implementation NSArray (randomized)
- (NSArray *) makeRandmizedArray
{
  NSMutableArray *results = [NSMutableArray arrayWithArray:self];
  int i = [results count];

  srand((unsigned) time(NULL));

  while (--i >0) {
    int j = rand() % (i+1);
    [results exchangeObjectAtIndex:i withObjectAtIndex:j];
  }
  return [NSArray arrayWithArray:results];
}
@end

int main(void) {
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  NSArray *users = [NSArray arrayWithObjects: @"たけお", @"きたけー", @"ぐっさん", @"おっくん", nil];
  NSArray *sorted_users = [users makeRandmizedArray];

  for (int i=0; i < [sorted_users count]; i++) {
    NSString *str = [sorted_users objectAtIndex: i];
    printf("%d : %s \n", i, [str UTF8String]);
  }

  [pool release];
}
