import os.path

def f2arr(fname):

    if type(fname) is str and os.path.isfile(fname)==True:
        new_file=open(fname, 'r+') #opens fname in read format
        file_array=[]
        for i in new_file:
            file_array.append(i.strip()) #removes white space (\n)
        return file_array
        new_file.close()
    elif os.path.isfile(fname) == False:
        print "file does not exist ... Exiting"
    else:
        print "file name is not a string"

def conv2int(list_name):
    new_list=[]
    for i in list_name:
        new_list.append(float(i))
    return new_list

def arr2f(arr_name):
    fwrite=False
    f_input=raw_input("What file do you want to output list? \n")
    if os.path.isfile(f_input)==True:
        check=raw_input("File exists.  Do you want to replace file? (Y/N) \n")
        if check.lower()=="y":
            fwrite=True
    else:
        fwrite=True
    if fwrite==True:
        print "good"
        new_file=open(f_input, 'w+')
        for i in arr_name:
            new_file.write(str(i) + "\n" )
        new_file.close()

fname = raw_input("enter file name to convert to list \n")
flist =f2arr(fname)
print flist
int_list =conv2int(flist)
print int_list
arr2f(int_list)
