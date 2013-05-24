# coding: utf-8
import random
import sys
 
reload(sys)
sys.setdefaultencoding('utf-8')
 
name_list = [
    u"おっくん",
    u"きたけー",
    u"たけお",
    u"ぐっさん"
]
 
random.shuffle(name_list)
print name_list[0], name_list[1], name_list[2], name_list[3]
