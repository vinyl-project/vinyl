#-*- coding:utf-8 -*-

from setuptools import setup, find_packages

setup(
    name = "auto-vinyl",
    version = "0.0.1",
    keywords = ("pip", "automation"),
    description = "GUI automation utility",
    long_description = "GUI automation utility",
    license = "MIT Licence",

    url = "https://github.com/vinyl-project/vinyl",
    author = "JasonWang",
    author_email = "jstzwj@aliyun.com",

    packages = find_packages(),
    include_package_data = True,
    platforms = "any",
    install_requires = []
)