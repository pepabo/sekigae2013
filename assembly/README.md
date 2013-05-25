# 席替えスクリプトアセンブリ言語版

## 実行方法

Linux 上で。

```
$ nasm -f elf sekigae.asm
$ ld -m elf_i386 -o sekigae sekigae.o
$ ./sekigae
ぐっさん
けおけん
おっくん
きたけー
```

## TODO

 * シードがハードコード
   * sgenrand 実行前に eax レジスタにシードをセットしてるが、結果を変えるにはこの値を変えてアセンブル＆リンクが必要
