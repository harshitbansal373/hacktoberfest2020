'''Simple inventory manager by: Khashayar Nariman.'''
# Importing our modules 1) tkinter for guipart 2) winsound for adding some beeps
# 3) shutil for file operations 
import tkinter as t, winsound, shutil
from tkinter import messagebox
from tkinter import *
# Create a list for keeping our entry data
items = []
# This function try to load the last data available in inventory_tem.txt
def backup():
    shutil.copy("inventory_temp.txt","inventory.txt")
    info_lable["text"] = "backup file loaded"
    
# This function gets our entry data from user
def add():
    name = item_entry.get()
    price = price_entry.get()
    quantity = quan_entry.get()
    info = info_entry.get()
    items.append([name,price,quantity,info])
    winsound.Beep(2000,50)
    item_entry.delete(0,"end")
    price_entry.delete(0,"end")
    quan_entry.delete(0,"end")
    info_entry.delete(0,"end")
    info_lable["text"] = name, "entered to database"
# This function use search to find and delete specific data from the list
def dell():
    search = search_entry.get()
    for item in items:
        if search in item:
            items.remove(item)
            info_lable["text"] = (item," found and removed")
# This function Loads the last data saved in inventory.text file
# and make an copy from data to inventory_temp.txt
# and delete the inventory.txt file
def load():
    file = open("inventory.txt","r")
    temp_file = open("inventory_temp.txt","w")
    shutil.copy("inventory.txt","inventory_temp.txt")
    for line in file.readlines():
        for item in line[0:-1].split("\n"):
            items.append(item)
    try:
        file = open ("inventory.txt","w")
        file.write()
        file.close()
        temp_file.close()
    except TypeError:
        messagebox.showinfo("Load", "complete")
# This function saves data from the list to the text file (inventory.txt)
# and delete the inventory_temp.txt file  
def save():
    file = open("inventory.txt","a")
    file.write("\n".join(str(i)for i in items))
    file.close()
    temp_file = open("inventory_temp","w")
    try:
        temp_file.write()
        temp_file.close()
    except TypeError:
        messagebox.showinfo("save","complete")
# This function displays a list of data available in our items list
def llist():
    root = Tk()
    scrollbar=Scrollbar(root)
    scrollbar.pack(side = RIGHT, fill = Y)
    listbox = Listbox(root)
    listbox.config(width=0)
    listbox.pack()
    for item in items:
        listbox.insert(END, item)
    listbox.config(yscrollcommand = scrollbar.set)
    scrollbar.config(command = listbox.yview)
# This function search an item in the list and displays the result
def search():
    search = search_entry.get()
    for item in items:
        if search in item:
            info_lable["text"] = item
            
# This function save the data to the inventory.txt file and exit the
# program,
def eexit():
    file = open("inventory.txt","a")
    file.write("\n".join(str(i)for i in items))
    file.close()
    temp_file = open("inventory_temp","w")
    try:
        temp_file.write()
    except TypeError:
        messagebox.showinfo("save","complete")  
    quit()
main_window = t.Tk()
main_window.title("INVENTORY")
top_frame = t.Frame(main_window)
top_frame.pack()
bot_frame = t.Frame(main_window)
bot_frame.pack()
l_frame = t.Frame(main_window)
l_frame.pack(side="left")
info_lable = t.Label(bot_frame, text = "")
info_lable.pack()
item_label = t.Label(top_frame,text="Item")
item_label.pack(side = "left")
item_entry = t.Entry(top_frame,width = 10)
item_entry.pack(side="left")
price_label = t.Label(top_frame, text = "Price")
price_label.pack(side="left")
price_entry = t.Entry(top_frame,width = 10)
price_entry.pack(side="left")
quan_label = t.Label(top_frame,text = "Quantity")
quan_label.pack(side="left")
quan_entry = t.Entry(top_frame, width = 10)
quan_entry.pack(side="left")
info_label = t.Label(top_frame,text = "Extra information")
info_label.pack(side="left")
info_entry = t.Entry(top_frame,width = 50)
info_entry.pack(side="left")
search_lable = t.Label(l_frame, text = "Search")
search_lable.pack(side = "left")
search_entry = t.Entry(l_frame, widt = 30)
search_entry.pack(side="left")
b_add = t.Button(l_frame, text = "ADD", command = add)
b_add.pack(side = "left")
b_del = t.Button(l_frame, text = "DEL", command = dell)
b_del.pack(side="left")
b_load = t.Button(l_frame, text ="Load", command = load)
b_load.pack(side = "left")
b_save = t.Button(l_frame, text ="Save", command = save)
b_save.pack(side = "left")
b_llist = t.Button(l_frame, text ="List", command = llist)
b_llist.pack(side = "left")
b_search = t.Button(l_frame, text ="Search",command = search)
b_search.pack(side = "left")
b_exit = t.Button(l_frame, text ="Save/Exit", command = eexit)
b_exit.pack(side ="right")
b_load_backup = t.Button(l_frame,text = "Load backup file",command = backup)
b_load_backup.pack(side="left")
    
main_window.mainloop()
