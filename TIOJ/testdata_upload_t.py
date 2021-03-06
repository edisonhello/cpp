"""TIOJ AUTO ADD Testdata Script"""

from __future__ import absolute_import
from __future__ import print_function
from __future__ import unicode_literals

import requests
import random
import string
from getpass import getpass as getpass
from bs4 import BeautifulSoup

# config

# the testdata will append at the end of the testdata list
input_suffix = '.in'
output_suffix = '.out'
filename_format = '%d%s'

# end config

   
session = requests.Session()

def login():
    print('Username: edisonhello')
    TIOJusername = 'edisonhello'
    TIOJpassword = getpass('Password: ')
    print('logging in...')
    global session
    rel = session.get('https://tioj.ck.tp.edu.tw/users/sign_in')
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')
    rel = session.post('https://tioj.ck.tp.edu.tw/users/sign_in', data = {
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        'user[username]': TIOJusername,
        'user[password]': TIOJpassword,
        'user[remember_me]': '1',
        'commit': 'Sign in'
    })

login()
print('Successful log in')
problem_id = int(input('Problem ID: '))
num_start = int(input('Testdata start number: '))
num_end = int(input('Testdata end number: '))
time_limit = int(input('Time limit: '))
memory_limit = int(input('Memory limit: '))

sign_up_get_url = 'https://tioj.ck.tp.edu.tw/problems/%s/testdata/new' % problem_id
sign_up_post_url = 'https://tioj.ck.tp.edu.tw/problems/%s/testdata' % problem_id

for i in range(num_start, num_end + 1):
    print('processing %d...' % i)
    rel = session.get(sign_up_get_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')

    rel = session.post(sign_up_post_url, data = {
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        'testdatum[limit_attributes][time]': time_limit,
        'testdatum[limit_attributes][memory]': memory_limit,
        'testdatum[limit_attributes][output]': '65536',
        'testdatum[problem_id]': problem_id,
        'commit': 'Create Testdatum'
    }, files = {
        'testdatum[test_input]': open(filename_format % (i, input_suffix), 'rb'),
        'testdatum[test_output]': open(filename_format % (i, output_suffix), 'rb')
    })
    print('%d created.' % i)
