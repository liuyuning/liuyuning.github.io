---
layout: default
title:  "用GitHub Page和Jekyll搭建博客-修改主题"
date:   2017-08-22 13:55:08 +0800
categories: blog

---

### 修改默认主题有两种方式

1. 在_layouts目录添加自己的主题，还包括_includes/_sass/assets
2. 修改Gemfile来加载现成的第三方主题，有点像CocoaPods

打开Gemfile

```text
gem "github-pages", group: :jekyll_plugins
```
然后更新Gemfile配置

```shell
$ bundle update
bundle update
The dependency tzinfo-data (>= 0) will be unused by any of the platforms Bundler is installing for. Bundler is installing for ruby but the dependency is only for x86-mingw32, x86-mswin32, x64-mingw32, java. To add those platforms to the bundle, run `bundle lock --add-platform x86-mingw32 x86-mswin32 x64-mingw32 java`.
Fetching gem metadata from https://rubygems.org/..........
Fetching version metadata from https://rubygems.org/..
...
Using jekyll-theme-primer 0.5.0
Using jekyll-theme-slate 0.1.0
Using jekyll-theme-tactile 0.1.0
Using jekyll-theme-time-machine 0.1.0
Using github-pages 155
Bundle updated!
```
看一下我们都下载那些主题，这些主题和GitHub官网推荐的主题是一样的

```shell
$ gem list jekyll-theme

*** LOCAL GEMS ***

jekyll-theme-architect (0.1.0)
jekyll-theme-cayman (0.1.0)
jekyll-theme-dinky (0.1.0)
jekyll-theme-hacker (0.1.0)
jekyll-theme-leap-day (0.1.0)
jekyll-theme-merlot (0.1.0)
jekyll-theme-midnight (0.1.0)
jekyll-theme-minimal (0.1.0)
jekyll-theme-modernist (0.1.0)
jekyll-theme-primer (0.5.1, 0.5.0)
jekyll-theme-slate (0.1.0)
jekyll-theme-tactile (0.1.0)
jekyll-theme-time-machine (0.1.0)
```

我们只要修改_config.yml里面的主题字段就可以使用了
theme: jekyll-theme-minimal

另外还有很多现成的第三方主题，可以在[https://rubygems.org/](https://rubygems.org/)搜索"jekyll theme"看到

gem uninstall listen
gem install listen
bundle

