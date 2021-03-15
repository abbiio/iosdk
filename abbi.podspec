Pod::Spec.new do |s|

  s.name         = "abbi"
  s.version      = "2.9.15"
  s.summary      = "Simple SDK for developers to manage and maximize conversions of all in-app promotions."
  s.description  = "In one line of code, ABBI provides the full life-cycle of in app marketing to your app. Create and manage your in app promotions and let ABBI do all the hard work and optimize your CTR's!"
  s.homepage     = "http://walkme.com"
  s.license      = "Commercial"
  s.author             = { "WalkMe Inc" => "http://walkme.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/abbiio/iosdk.git", :tag => s.version }

  s.preserve_paths = "WalkMeSDK.framework"
  s.frameworks = "CoreMotion", "UIKit", "Social", "StoreKit", "SystemConfiguration", "WebKit", "AudioToolbox"
  s.requires_arc = true
  s.xcconfig = { "HEADER_SEARCH_PATHS" => "\"$(PODS_ROOT)/abbi\"", "OTHER_LDFLAGS" => "-ObjC" }
  s.vendored_frameworks = 'WalkMeSDK.framework'

end
