# -*- coding: utf-8 -*-
"""
Created on Sat Feb  2 13:14:48 2019

@author: sanath
"""
hostnames = ['10.245.0.100','10.245.0.800','google.com','10.45.80.21','10.33.33.21'] 
#example

#mylist = 0
#liste = 0

#for i in hostname:
#    value = os.system("ping -c 1" + i)
#    print("ip er ", i)
#    print(value)
#    if value == "1":
#        print("skrammel")
# 
#print("værdien er", i)



import os
import csv

liste2 = []

for hostname in hostnames:
    response = os.system('ping -c 1 ' + hostname)
if response == 0:
    print (hostname, 'is up')
elif response == 1:
    print (hostname, 'is down')
    with open('bruger.csv', 'a', newline ="\n") as fd:
        fd.write(hostname+",")
        fd.close()


print ("Første kørsel gennemført")

with open('bruger.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    line_count = 0
    for row in csv_reader:
        response2 = os.system('ping -c 1 ' + hostname)
    if response == 0:
        print(hostname, 'is up')
    elif response == 1:
        print(hostname, 'is down')
    print('Processed {line_count} lines.')
