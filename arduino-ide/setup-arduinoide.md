# Arduino IDE開発環境
Arduino IDEでの開発環境設定  
（RP2040側の開発はまだできていないので記載しない）

## ボード設定(ESP32S3)
- 使用バージョン
  - esp32 2.0.11

1. 公式Wiki↓の通りにボード「ESP32S3 Dev Module」を設定・PSRAMを「OPI PSRAM」に設定
https://wiki.seeedstudio.com/SenseCAP_Indicator_ESP32_Arduino/#software-preparation
1. 「ESP32S3 Dev Module」が設定できない場合は下記サイトを参考にボードマネージャーから追加  
https://karakuri-musha.com/inside-technology/arduino-ide2x-install-board-manager/  
MEMO:手元の環境ではpreference(基本設定)の追加URL設定をしなくても通った。最近変わった？
1. シリアルポート設定はデバイスマネージャーから、「USB-SERIAL CH340」と記載される方のポートを参照

## 使用ライブラリ
| ライブラリ | バージョン |
| --- | --- |
| LovyanGFX | 1.1.9 |
|  |  |
- LovyanGFXについて
  - https://karakuri-musha.com/inside-technology/arduino-m5stack-display-02-lovyangfx/
  - M5などの画面制御と同様の操作が可能

## 注意事項
- タッチスクリーンの使用ができない可能性がある？
  - 最初にArduino IDEを使用したときは、タッチが使用できなかったが、一度PlatformIOで使用できるようにした後は使用できた
  - 公式WikiでもIOエキスパンダによる不具合が問題に上がっている  
  `    There is still Phase ONE for the development and what is not configured in this tutorial is the touchscreen part. I already try few arduino library for the FT6336 module but none have a successful result.`

    `This due to the INT Pin and RESET pin of the FT6366 module connected to the PCA9535 I2C expander and it need to configured manually in the library. I might get back to try this in the future.`