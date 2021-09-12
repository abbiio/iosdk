// swift-tools-version:5.3

import PackageDescription

let package = Package(
  name: "WalkMeSDK",
  products: [.library(name: "WalkMeSDK",
                      targets: ["WalkMeSDK"])],
  targets: [.binaryTarget(name: "WalkMeSDK",
                          url: "https://assets.abbi.io/release/sdk/2.12.0.xcframework.zip",
                          checksum: "d2b98bbea86dc8436925c8cde58fd64f83a5daa9767e3d6a87ddaf28bd8a97ce")],
  swiftLanguageVersions: [.v5]
)
