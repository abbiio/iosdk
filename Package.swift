// swift-tools-version:5.3

import PackageDescription

let package = Package(
  name: "WalkMeSDK",
  products: [.library(name: "WalkMeSDK",
                      targets: ["WalkMeSDK"])],
  targets: [.binaryTarget(name: "WalkMeSDK",
                          url: "https://assets.abbi.io/release/sdk/2.12.0.xcframework.zip",
                          checksum: "142f4df3ecfb38753a7e9696e152cf15338b7fb463cfe92420c0f670cc6091fa")],
  swiftLanguageVersions: [.v5]
)
