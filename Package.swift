// swift-tools-version:5.3

import PackageDescription

let package = Package(
  name: "WalkMeSDK",
  products: [.library(name: "WalkMeSDK",
                      targets: ["WalkMeSDK"])],
  targets: [.binaryTarget(name: "WalkMeSDK",
                          url: "https://assets.abbi.io/release/sdk/2.12.0.xcframework.zip",
                          checksum: "fcf13bfda57662281cee8a2ef2566f1a6177da8a8e6903e15d451211506eddb0")],
  swiftLanguageVersions: [.v5]
)
