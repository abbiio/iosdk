// swift-tools-version:5.3

import PackageDescription

let package = Package(
  name: "WalkMeSDK",
  products: [
    .library(name: "WalkMeSDK", targets: ["WalkMeSDK"])
  ],
  dependencies: [
  ],
  targets: [
    .binaryTarget(name: "WalkMeSDK", path: "WalkMeSDK.xcframework")
  ]
)
