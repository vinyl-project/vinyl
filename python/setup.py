#-*- coding:utf-8 -*-

from setuptools import setup, find_packages

setup(
    name = "pyvinyl",
    version = "0.1.2",
    keywords = ("pip", "automation", "gui", "test"),
    description = "GUI automation utility",
    long_description = "GUI automation utility",
    license = "MIT Licence",

    url = "https://github.com/vinyl-project/vinyl",
    author = "VinylProject",
    author_email = "admin@octoon.org",

    packages = find_packages(),
    include_package_data = True,
    platforms = "any",
    install_requires = ["numpy"]
)