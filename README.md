# ViveController-RTM-pkg

## 1. 概要
VRデバイスの1つであるHTC社のVIVEを対象として，その機能を簡易的な利用を可能にするRTコンポーネント群

## 2. 開発環境
### 2.1. 開発環境一覧
- PC：ZBOX-EN1070-U
- OS：Windows 10
- ソフトウェア：CMake / OpenRTM-aist-1.2.0-RELEASE
- ハードウェア：HTC VIVE / HTC VIVE トラッカー 2018
- 開発言語：C/C++

### 2.2. HTC VIVE / HTC VIVE Tracker 2018
VRデバイスの1つであるHTC VIVEとHTC VIVE Tracker 2018の機能について以下に示す．HTC VIVEにはヘッドマウントディスプレイ(以下，HMD)，コントローラ，ベースステーションが含まれている.
### 2.2.1. HMD
![VIVE HMD](images/vive-hardware-hmd-1.png)
### 2.2.2. コントローラ
![VIVEコントローラ](images/vive-hardware-controllers-1.png)
### 2.2.3. ベースステーション
![VIVEベースステーション](images/vive-hardware-base-stations.png)
### 2.2.4. トラッカー
![VIVEトラッカー](images/vive-hardware-tracker-1.png)

## 3. 開発コンポーネントの概要
### ViveController
本コンポーネントは以下の4つの機能をもつ  
- VIVEコントローラの位置姿勢/ボタン情報の管理   
- VIVE HMDの位置姿勢の管理
- VIVEトラッカーの位置姿勢の管理
- VIVE HMDへの画像の出力

### コンポーネントができ次第随時更新いたします
