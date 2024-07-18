import os, sys, shutil

args = sys.argv[1:]
if len(args) == 0: args.append('')

bin_dir   =   'bin'
build_dir =   'build'
lib       =   'jmpc'
lib_src   = [ 'impl/types',
              'impl/math',
              'impl/mem',
              'impl/str',
              'impl/os',
              'impl/ll',
              'impl/arr', ]
opt_src   = [ 'impl/opt/render',
              'impl/opt/debug', ]
lib_obj   = []

lib_inc_dir = 'jmpc/include'

def write_header(txt: str, color: str) -> None:
  col = ''
  match color.lower():
    case 'black':      col = '\033[0;30m'
    case 'red':        col = '\033[0;31m'
    case 'green':      col = '\033[0;32m'
    case 'yellow':     col = '\033[0;33m'
    case 'blue':       col = '\033[0;34m'
    case 'magenta':    col = '\033[0;35m'
    case 'cyan':       col = '\033[0;36m'
    case 'light grey': col = '\033[0;37m'
    case _:            col = ''
  print(f'{col}{txt}\033[0m')
  
def build_obj(file: str) -> None:
  os.system(f'gcc -I{lib_inc_dir} -Ilib/stb -std=c99 -Wno-incompatible-pointer-types -c -o {build_dir}/{file}.obj jmpc/src/{file}.c')
  lib_obj.append(f'build/{file}.obj')
  
def check_dir_exists(file: str) -> None:
  p = file.split('/')
  
  if len(p) == 1: return

  p = p[:-1]
  
  path = 'build'
  for d in p:
    tpath = f'{path}/{d}'
    if not os.path.exists(tpath): os.makedirs(tpath)
    path += f'/{d}'
  
def build_test() -> None:
  # Todo - include libgdi in jmpc.lib, instead of having to manually include it.
  write_header('=== Build Tests ===', 'blue')
  os.system(f'gcc -I{bin_dir}/jmpc/include -std=c99 -Wno-incompatible-pointer-types -o {bin_dir}/test.exe test/main.c {bin_dir}/jmpc/jmpc.lib lib/gdi32.lib')
  
if args[0] == 'test-only':
  build_test()
  quit()
  
# Todo - check if the `build` and `bin` dirs exist.
if not os.path.exists(f'./{bin_dir}'):      os.makedirs(bin_dir)
if not os.path.exists(f'./{build_dir}'):    os.makedirs(build_dir)

if not os.path.exists(f'./{bin_dir}/jmpc'):         os.makedirs(f'{bin_dir}/jmpc')

write_header(' === Compile Objects ===', 'blue')

for file in lib_src:
  check_dir_exists(file)
  write_header(f'compiling {file}.c', 'green')
  build_obj(file)
  
if 'opt' in args:
  for file in opt_src:
    check_dir_exists(file)
    write_header(f'compiling {file}.c', 'green')
    build_obj(file)

write_header(' === Linking ===', 'blue')

shutil.rmtree(f'{bin_dir}/jmpc/include')
shutil.copytree('./jmpc/include', f'{bin_dir}/jmpc/include', False, None)
if not 'opt' in args:
  shutil.rmtree(f'{bin_dir}/jmpc/include/opt')
  shutil.rmtree(f'{bin_dir}/jmpc/include/stb')

files = ' '.join(lib_obj)
os.system(f'ar rcs {bin_dir}/jmpc/{lib}.lib {files}')


if 'test' in args:
  build_test()
