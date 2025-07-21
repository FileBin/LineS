with (import <nixpkgs> {  });
mkShell {
    buildInputs =
    # nix qt does not work well on darwin so it should be installed via homebrew
    (with kdePackages; pkgs.lib.optionals pkgs.stdenv.isLinux [
        qtbase
        qtdeclarative
        qttools
        qtsvg
        qtimageformats
        qtshadertools
        qtmultimedia
        qtserialport
        qtwebsockets
        qtconnectivity
        qtcharts
        qtdatavis3d
        qttools
        qtwayland
    ]) ++ [
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
    # TODO: this should export only on darwin
    shellHook = ''
        export PKG_CONFIG_PATH_FOR_TARGET="$PKG_CONFIG_PATH_FOR_TARGET:/opt/homebrew/opt/qt/lib/pkgconfig"
    '';
}
