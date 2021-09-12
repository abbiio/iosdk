// swift-tools-version:5.3

import PackageDescription

let package = Package(
  name: "WalkMeSDK",
  products: [.library(name: "WalkMeSDK",
                      targets: ["WalkMeSDK"])],
  targets: [.binaryTarget(name: "WalkMeSDK",
                          url: "https://assets.abbi.io/release/sdk/2.12.0.xcframework.zip",
                          checksum: "52d3bb24a41a01923c8edb1ae6b72975fed93c7ac1ffeb6e2745611698be6c03")],
  swiftLanguageVersions: [.v5]
)
