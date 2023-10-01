{
  description = "Tasksfire development environment for NixOS";
  
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-23.05";
  };

  outputs = { self , nixpkgs ,... }: let
    system = "x86_64-linux";
    in 
    {
    devShells."${system}".default = let
      pkgs = import nixpkgs {
        inherit system;
      };
    in pkgs.mkShell {
      name = "cppEnv";

      packages = with pkgs; [
        gcc
        qt6.full
        gnumake
        fish
      ];

      shellHook = ''
        clear
        fish
        exit
      '';
    };
  };
}
