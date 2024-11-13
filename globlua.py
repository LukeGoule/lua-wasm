import glob

directory = 'lua_src'
c_files = glob.glob(f'{directory}/*.c')
c_files_string = ' '.join(c_files)
print(c_files_string)