#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
Created on Nov 30, 2017
@author: Ufidon
'''

# 将正整数I转化为b进制
def iconvert(I,b):
	d=[]
	while(I):
		d.append(I%b)
		I=int(I/b)
	if(I%b):
		d.append(I%b)
	#print(d[::-1])
	return d[::-1]



# 将小数 0<= f <1转换成b进制不超过n小数位
def fconvert(f,b,n):
	d=[]
	i=0
	while(f and i<n):
		d.append(int(f*b))
		f=f*b-int(f*b)
		i=i+1
	#print(d)
	return d

if __name__ == '__main__':
	
	print(iconvert(5,2))
	print(iconvert(5,16))
	print(iconvert(8,2))
	
	print("\n")
	print(fconvert(0.125,2,4))
	print(fconvert(0.125,3,4))
	print(fconvert(0.125,4,4))
	print(fconvert(0.125,5,4))
	print(fconvert(0.125,6,4))
	print(fconvert(0.6,4,30))
	
	pass