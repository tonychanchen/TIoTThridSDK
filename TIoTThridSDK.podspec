Pod::Spec.new do |s|
  s.name             = 'TIoTThridSDK'
  s.version          = '1.0.4'
  s.summary          = '该仓库为方便个人仓库构建使用，如有其他需求还请从官网下载原SDK'

  s.description      = <<-DESC
在CI构建中，有些SDK没有提供供方便pod集成使用，在此仓库提供个聚合SDK以便更好的支持CI。
                       DESC
                       
  s.homepage         = 'https://github.com/tonychanchen/TIoTThridSDK'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'tonychanchen@gmail.com' => 'tonychanchen@gmail.com' }
  s.source           = { :git => 'https://github.com/tonychanchen/TIoTThridSDK.git', :tag => s.version.to_s }

  s.ios.deployment_target = '10.0'     
#  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-all_load' }
#  s.static_framework = true
  s.default_subspec = 'Default'
  
  s.subspec 'Default' do |ss|
    ss.source_files          = 'TIoTThridSDK/TIoTThridSDK.h'
  end
     
  s.subspec 'TPNS-iOS' do |ss|
    ss.source_files          = 'TIoTThridSDK/TPNS-iOS/Classes/**/*'
    ss.vendored_libraries    = 'TIoTThridSDK/TPNS-iOS/libXG-SDK-Cloud.a', 'TIoTThridSDK/TPNS-iOS/libxgidfa.a', 'TIoTThridSDK/TPNS-iOS/libXGExtension.a'
    ss.vendored_frameworks   = 'TIoTThridSDK/TPNS-iOS/XGMTACloud.framework'
    ss.frameworks            = "CFNetwork", "SystemConfiguration", "CoreTelephony", "CoreGraphics", "Foundation", "UserNotifications", "CoreData"
    ss.libraries             = "z", "sqlite3"
    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end

  s.subspec 'WechatOpenSDK_NoPay' do |ss|
    ss.source_files          = 'TIoTThridSDK/WechatOpenSDK_NoPay/Classes/**/*'
    ss.vendored_libraries    = 'TIoTThridSDK/WechatOpenSDK_NoPay/libWeChatSDK.a'
    ss.frameworks            = "Security", "CoreGraphics", "WebKit", "SystemConfiguration", "CoreTelephony", "Foundation", "UIKit"
    ss.libraries             = 'c++', 'sqlite3', 'z'
    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end
  
  s.subspec 'FFmpeg-iOS' do |ss|
    ss.source_files        = 'TIoTThridSDK/FFmpeg-iOS/include/**/*.h'
    ss.vendored_libraries  = 'TIoTThridSDK/FFmpeg-iOS/lib/*.a'
    ss.frameworks            = "AudioToolbox", "AVFoundation", "OpenGLES", "CoreImage", "CoreGraphics", "CoreMedia", "VideoToolbox"
    ss.libraries             = 'z', 'bz2', 'iconv'
    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end
  
  s.subspec 'XP2P-iOS' do |ss|
    ss.source_files          = 'TIoTThridSDK/XP2P-iOS/Classes/**/*'
    ss.vendored_libraries    = 'TIoTThridSDK/XP2P-iOS/*.a'
    ss.frameworks            = "NetworkExtension", "CoreGraphics", "SystemConfiguration", "Foundation", "UIKit"
    ss.libraries             = 'c++', 'sqlite3', 'z'
    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end
  
    s.subspec 'Faac-iOS' do |ss|
    ss.source_files          = 'TIoTThridSDK/Faac-iOS/Classes/**/*'
    ss.vendored_libraries    = 'TIoTThridSDK/Faac-iOS/*.a'
    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end
end
