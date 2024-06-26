Pod::Spec.new do |s|

  s.name         = "abbi"
  s.version      = "2.18.7"
  s.summary      = "Simple SDK for developers to manage and maximize conversions of all in-app promotions."
  s.description  = "In one line of code, ABBI provides the full life-cycle of in app marketing to your app. Create and manage your in app promotions and let ABBI do all the hard work and optimize your CTR's!"
  s.homepage     = "http://walkme.com"
  s.license      = "Commercial"
  s.platform     = :ios, "11.0"
  s.requires_arc = true
  s.author       = { "WalkMe Inc" => "http://walkme.com" }
  s.source       = { :git => "https://github.com/abbiio/iosdk.git", :tag => s.version }
  s.xcconfig     = { "HEADER_SEARCH_PATHS" => "\"$(PODS_ROOT)/abbi\"", "OTHER_LDFLAGS" => "-ObjC" }
  s.frameworks   = "CoreMotion", "UIKit", "Social", "StoreKit", "SystemConfiguration", "WebKit", "AudioToolbox"

  s.default_subspecs = 'Main'

  s.subspec 'Main' do |ss|
    
    ss.preserve_paths = "WalkMeSDK.xcframework"
    ss.vendored_frameworks = 'WalkMeSDK.xcframework'

  end

  s.subspec 'XCFramework' do |ss|

    ss.preserve_paths = "WalkMeSDK.xcframework"
    ss.vendored_frameworks = 'WalkMeSDK.xcframework'

  end

  s.subspec 'Legacy' do |ss|

    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

    ss.preserve_paths = "WalkMeSDK.framework"
    ss.vendored_frameworks = 'WalkMeSDK.framework'

  end

end
