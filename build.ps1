param(
    [String]$test=""
)

if ($test -eq "help") {
    echo "JmpC Build script options:"
    echo " ./build <Empty>   :: Build the library"
    echo " ./build test      :: Build the library and test files"
    echo " ./build test-only :: Build only the test files"
    Exit
}

# ====== DATA DIVISION ======
$lib = "jmpc"


$lib_src = @( # The source files for the library.
    "impl/types",
    "impl/math",
    "impl/mem",
    "impl/str",
    "impl/os",
    "impl/ll",
    "impl/opt/render",
    "impl/opt/debug"
)

$lib_obj = @()

# ====== PROCEDURE DIVISION ======
function Write-ColorOutput {
    param($ForegroundColor)

    # save the current color
    $fc = $host.UI.RawUI.ForegroundColor

    # set the new color
    $host.UI.RawUI.ForegroundColor = $ForegroundColor

    # output
    if ($args) {
        Write-Output $args
    }
    else {
        $input | Write-Output
    }

    # restore the original color
    $host.UI.RawUI.ForegroundColor = $fc
}

function obj {
    param($file)

    # TODO - Make directory structure in build dir.
    gcc -Ijmpc/include -Ilib/stb -std=c99 -Wno-incompatible-pointer-types -c -o build/$file.obj jmpc/src/$file.c 
    return "build/$file.obj"
}

function test {
    # TODO - fix libgdi32 not linking properly.
    gcc -Ijmpc/include -std=c99 -Wno-incompatible-pointer-types -Wno-shift-overflow -o bin/test.exe test/main.c bin/jmpc.lib lib/gdi32.lib
}

# This absolute mess of a function makes sure that
# directories exist in the /build path, so that we
# can actually build the file.
function get_file_dir {
    param($file)

    # There are a *lot* of temp variables because I'm not very 
    # famililar with powershell.
    $p = $file -split '/'

    if ($p.length -eq 1) { return }

    $tmp = $p[-$p.length..-2]
    
    $path = 'build'
    foreach ($d in $tmp) {
        $tpath = $path + '/' + $d

        if (!(Test-Path $tpath)) { New-Item -Path $path -Name $d -ItemType Directory }
        $path += '/' + $d
    }
}

# ====== SCRIPT CODE ======

# Make sure the bin and build directories exist.
if (!(Test-Path "bin"))   { New-Item -Path ".\" -Name "bin"   -ItemType Directory }
if (!(Test-Path "build")) { New-Item -Path ".\" -Name "build" -ItemType Directory }

if ($test -eq "test-only") {
    Write-ColorOutput blue (echo "=== Building test files ===")
    test
    Exit
}

# Compile every .c file down to a .obj
Write-ColorOutput blue (echo "=== Compiling ===")
foreach ($file in $lib_src) {
    get_file_dir $file
    Write-ColorOutput green (echo "compiling $file.c")
    $lib_obj += obj $file
}

Write-ColorOutput blue (echo "=== Linking ===")
$l = $lib_obj -join ' '
ar rcs bin/$lib.lib $lib_obj

# If testing, compile the test script
# TODO - either track updates to the library, or have option to avoid compiling the library.
if ($test -eq "test") {
    Write-ColorOutput blue (echo "=== Building test files ===")
    test
}
