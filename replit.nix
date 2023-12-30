{ pkgs }: {
    deps = [
        pkgs.dotnet-sdk
      pkgs.zip
      pkgs.edit
      pkgs.unzip
        pkgs.graalvm17-ce
        pkgs.maven
        pkgs.replitPackages.jdt-language-server
        pkgs.replitPackages.java-debug
    ];
}