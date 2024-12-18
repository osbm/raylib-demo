{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
  };

  outputs =
    {
      self,
      nixpkgs,
      ...
    }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs {
        inherit system;
      };
    in
    {
      packages."${system}" = {
        raylib-demo = pkgs.stdenv.mkDerivation {
          name = "raylib-demo";
          version = "0.1.0";
          buildInputs = with pkgs; [
            libGL

            # X11 dependencies
            xorg.libX11
            xorg.libX11.dev
            xorg.libXcursor
            xorg.libXi
            xorg.libXinerama
            xorg.libXrandr

            raylib
          ];
          src = ./.;
          # XDG_RUNTIME_DIR = "/tmp";
        };
        default = self.outputs.packages."${system}".raylib-demo;
      };
    };
}
