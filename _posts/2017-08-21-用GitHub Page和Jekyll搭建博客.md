---
layout: default
title:  "用GitHub Page和Jekyll搭建博客"
date:   2017-08-21 17:05:08 +0800
categories: blog

---

<!--## 用GitHub Page和Jekyll搭建博客-->
GitHub地球人都能用，所以也想把博客也搬到这里，方便阅读。下面就自己搭建博客的过程，记录下来备忘。

### 1、比较
现在网上有很多和GitHub Page搭配的方案，比如Hugo，Hexo、Jekyll、Octopress，实际上在GitHut搜索一下就能看到各种各样的主页。既然是GitHub推荐，那么就用[Jekyll](http://jekyllcn.com/)来做吧。
<br/>很奇怪Jekyll中文有两个网站[jekyllcn.com](http://jekyllcn.com/)， [jekyll.com.cn](http://jekyll.com.cn/)
<br/>[知乎上比较的帖子](https://www.zhihu.com/question/20376047?sort=created)


### 2、系统和工具

1. 操作系统 macOS Sierra 10.12.6
2. MarkDown编辑工具，自用的是MacDown <br/>[Mou](http://25.io/mou/)，暂时支持到macOS 10.11<br/>[Haroopad](http://pad.haroopress.com/user.html)，支持多系统，支持预览，字体有点难看，没细研究<br/>[MacDown](https://macdown.uranusjr.com/)，可以实时预览，如果不熟语法，打开“MarkDown帮助”里面就有例子<br>更多参考[知乎的帖子](https://www.zhihu.com/question/22700184) 
3. brew ([Homebrew](https://brew.sh/))，是Mac下的软件包管理工具，类似于apt-get
4. gem ([RubyGems](https://rubygems.org/))，是Ruby的软件包管理工具，类似于apt-get
5. 还有Ruby和Ruby的软件包Jekyll、Bundler

### 3、开始安装
**Mac系统默认的Ruby版本太低，同时需要用到系统权限，所以我们先安装brew，再更新Ruby**

```shell
$ which ruby
/usr/bin/ruby
$ ruby --version
ruby 2.0.0p648 (2015-12-16 revision 53162) [universal.x86_64-darwin16]

$ gem install jekyll
Fetching: public_suffix-2.0.5.gem (100%)
ERROR:  While executing gem ... (Gem::FilePermissionError)
You don't have write permissions for the /Library/Ruby/Gems/2.0.0 directory.

...
liquid requires Ruby version >= 2.1.0.
#安装失败，提示Ruby版本太低
```
1、安装HomeBrew
打开[https://brew.sh/](https://brew.sh/)就能看到，只用一条命令就可以安装好

```shell
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```
2、更新Ruby

```shell
$ brew install ruby
==> Downloading https://homebrew.bintray.com/bottles/ruby-2.4.1_1.sierra.bottle.tar.gz
Already downloaded: /Users/liuyuning/Library/Caches/Homebrew/ruby-2.4.1_1.sierra.bottle.tar.gz
==> Pouring ruby-2.4.1_1.sierra.bottle.tar.gz
==> Caveats
Emacs Lisp files have been installed to:
/usr/local/share/emacs/site-lisp/ruby
==> Summary
🍺  /usr/local/Cellar/ruby/2.4.1_1: 1,191 files, 15.5MB
```
Brew安装后路径都变为local下，系统默认在"/usr/bin/ruby"和"/usr/bin/gem"

```shell
$ which ruby
/usr/local/bin/ruby
$ which gem
/usr/local/bin/gem
```
3、再安装jekyll

```shell
$ gem install jekyll
Done installing documentation for public_suffix, addressable, colorator, rb-fsevent, ffi, rb-inotify, sass-listen, sass, jekyll-sass-converter, listen, jekyll-watch, kramdown, liquid, mercenary, forwardable-extended, pathutil, rouge, safe_yaml, jekyll after 27 seconds
19 gems installed
```
同时gem包的安装路径也有变化<br/>"/Library/Ruby/Gems/2.0.0/gems/"变为"/usr/local/lib/ruby/gems/2.4.0/gems/"

4、测试新建站点

```shell
$ jekyll new mysite
Dependency Error: Yikes! It looks like you don't have bundler or one of its dependencies installed. In order to use Jekyll as currently configured, you'll need to install this gem. The full error message from Ruby is: 'cannot load such file -- bundler' If you run into trouble, you can find helpful resources at https://jekyllrb.com/help/! 
```
提示缺少bundler，再安装bundler

5、安装bundler（实际上少哪个装哪个）

```shell
$ gem install bundler
Fetching: bundler-1.15.4.gem (100%)
Successfully installed bundler-1.15.4
Parsing documentation for bundler-1.15.4
Installing ri documentation for bundler-1.15.4
Done installing documentation for bundler after 3 seconds
1 gem installed
```

### 4、新建站点
1、新建站点

```shell
$ jekyll new mysite
Running bundle install in /Users/liuyuning/tmp/mysite... 
Bundler: The dependency tzinfo-data (>= 0) will be unused by any of the platforms Bundler is installing for. Bundler is installing for ruby but the dependency is only for x86-mingw32, x86-mswin32, x64-mingw32, java. To add those platforms to the bundle, run `bundle lock --add-platform x86-mingw32 x86-mswin32 x64-mingw32 java`.
Bundler: Fetching gem metadata from https://rubygems.org/...........
Bundler: Fetching version metadata from https://rubygems.org/..
Bundler: Fetching dependency metadata from https://rubygems.org/.
Bundler: Resolving dependencies...
Bundler: Using public_suffix 2.0.5
Bundler: Using bundler 1.15.3
Bundler: Using colorator 1.1.0
Bundler: Using ffi 1.9.18
Bundler: Using forwardable-extended 2.6.0
Bundler: Using rb-fsevent 0.10.2
Bundler: Using kramdown 1.14.0
Bundler: Using liquid 4.0.0
Bundler: Using mercenary 0.3.6
Bundler: Using rouge 1.11.1
Bundler: Using safe_yaml 1.0.4
Bundler: Using addressable 2.5.1
Bundler: Using rb-inotify 0.9.10
Bundler: Using pathutil 0.14.0
Bundler: Using sass-listen 4.0.0
Bundler: Using listen 3.0.8
Bundler: Using sass 3.5.1
Bundler: Using jekyll-watch 1.5.0
Bundler: Using jekyll-sass-converter 1.5.0
Bundler: Using jekyll 3.5.2
Bundler: Fetching jekyll-feed 0.9.2
Bundler: Installing jekyll-feed 0.9.2
Bundler: Fetching minima 2.1.1
Bundler: Installing minima 2.1.1
Bundler: Bundle complete! 4 Gemfile dependencies, 22 gems now installed.
Bundler: Use `bundle info [gemname]` to see where a bundled gem is installed.
New jekyll site installed in /Users/liuyuning/tmp/mysite. 
```
看看都生成了哪些文件

```shell
$ tree mysite/
mysite/
├── 404.html
├── Gemfile
├── Gemfile.lock
├── _config.yml
├── _posts
│   └── 2017-08-21-welcome-to-jekyll.markdown
├── about.md
└── index.md

1 directory, 7 files
```

2、运行站点（实际部署时不需要）

```shell
$ cd mysite/
$ jekyll serve

Configuration file: /Users/liuyuning/tmp/mysite/_config.yml
Source: /Users/liuyuning/tmp/mysite
Destination: /Users/liuyuning/tmp/mysite/_site
Incremental build: disabled. Enable with --incremental
Generating... 
done in 0.281 seconds.
Auto-regeneration: enabled for '/Users/liuyuning/tmp/mysite'
Server address: http://127.0.0.1:4000/
Server running... press ctrl-c to stop.
[2017-08-14 18:55:14] ERROR `/favicon.ico' not found.
```
运行后生成"mysite/_site/"，里面生成了临时的html等<br/>
访问[http://127.0.0.1:4000/](http://127.0.0.1:4000/)，如图
<img src="{{ site.url }}/images/mysite.png" border="1" bordercolor="#000000"/>
<!--![]({{ site.url }}/images/mysite.png)-->

3、添加博客

在"_posts"目录里面添加markdown文件就是博客了，Jekyll的server会自动生成预览。

### 4、部署
首先在GitHub创建一个用户名开头的Repo，如liuyuning.github.io.git<br/>再执行一堆下面的Git命令，然后访问https://liuyuning.github.io/就能看到了

```shell
$ cd mysite/
$ git init
$ git remote add liuyuning  https://github.com/liuyuning/liuyuning.github.io.git
$ git pull liuyuning master --allow-unrelated-histories
$ git add .
$ git commit -m "first commit"
$ git push liuyuning master
```
#### 参考
* 如何撰写，加入评论，流量统计[http://www.jianshu.com/p/ffbbed22f984](http://www.jianshu.com/p/ffbbed22f984)
* Home Page [https://github.com/liuyuning/](https://liuyuning.github.io/)
* GitHub [https://github.com/liuyuning/](https://github.com/liuyuning/)
