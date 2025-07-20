with (import <nixpkgs> {  });
mkShell {
    buildInputs =
    with kdePackages; [
        qtbase
        qtdeclarative
        qttools
        qtsvg
        qtimageformats
        qtshadertools
        qtwayland
        qtmultimedia
        qtserialport
        qtwebsockets
        qtconnectivity
        qtcharts
        qtdatavis3d
        qttools
    ] ++ [
        # builder
        meson
        mesonlsp
        ninja
        cmake
        pkg-config
        
        # compilers
        libgcc
        rustup
        
        # tools
        clang-tools
        rust-cbindgen

        # debugger
        gdb
    ];

    packages = [
        nixfmt
        (vscode-with-extensions.override {
            vscodeExtensions = with vscode-extensions; [
                llvm-vs-code-extensions.vscode-clangd
                ms-vscode.cpptools
                ms-vscode.hexeditor
                tal7aouy.icons
                jnoortheen.nix-ide
                wmaurer.change-case
                mesonbuild.mesonbuild
                rust-lang.rust-analyzer
            ] ++ vscode-utils.extensionsFromVscodeMarketplace [
                {
                    name = "qt-ui";
                    publisher = "TheQtCompany";
                    version = "1.7.0";
                    hash = "sha256-XDOIyCZIUYPGfcszZMUkR9MHH+zrXZgympKNhcQwITY=";
                }
                {
                    name = "qt-core";
                    publisher = "TheQtCompany";
                    version = "1.7.0";
                    hash = "sha256-2413vMpvxSYBKpaD14sMgI92W8NtCYa/sJ7PZO62WfY=";
                }
            ];
        })
    ];
}
