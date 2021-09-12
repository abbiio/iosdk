// swift-tools-version:5.3

import PackageDescription

let package = Package(
  name: "WalkMeSDK",
  products: [.library(name: "WalkMeSDK",
                      targets: ["WalkMeSDK"])],
  targets: [.binaryTarget(name: "WalkMeSDK",
                          url: "https://assets.abbi.io/release/sdk/2.12.0.xcframework.zip",
                          checksum: "ceaca1a932484ca95bd296c158642901be64562a0f9849fa5cc4af87347164f1")],
  swiftLanguageVersions: [.v5]
)
