MINT-WAXED : RESTful Resume Service
===================================

INSTALL
-------

Installing this project should be straightforward for Linux/C++ developers.
- Download, build and install [C2Serve REST framework.](http://www.c2serve.eu/c2s-htdocs/overview.html)
- Install Mongo DB (http://www.mongodb.org/) packages for your distro and start mongod.
- Download this codebase.
- Install resume.js into your mongo instance.
> mongod resume.js
- Download and install [QT Creator.](http://qt.digia.com/product/developer-tools/)


RUNNING
-------

- Update the file paths in the mint-waxed.pro file to your locations.
- Start QT Creator and open this project using the mint-waxed.pro project descriptor file.
- Copy the test/testResumeService.html and test/FordyceResume.html files into your Apache or web server directory.
- Build and run the project
- Navigate your web browser to the testResumeService.html file.  All tests should pass.
- Navigate your web browser to the FordyceResume.html file and see the final result.


REST IMPLEMENTATION
-------------------

This project implements a REST web service which serves my resume information via endpoints.  The web service was built using the simple and powerful [C2Serve framework.](http://www.c2serve.eu/c2s-htdocs/overview.html).
I am not affiliated with C2Serve in any way, and discovered it via a link in [Wikipedia](http://en.wikipedia.org/wiki/List_of_web_service_frameworks) at the outset of this project.

All endpoints deliver JSON data, with a CORS header.  The base URL is http://<server>:8080/resume/ and the endpoints are:
- *contact* - my contact information,
- *summary* - a short description of my experience,
- *companies* - a list of the companies where I've held professional positions,
- *roles* - a list of positions, titles and detailed information about my work,
- *education* - a list of my educational accomplishments,
- *skills* - a list of software technologies I have experience working with.


DATABASE
--------

I chose to use [Mongo DB](http://www.mongodb.org/) because it was new to me, and had a well-documented C++ API.  Its BSON interface also dovetailed nicely with the web service's JSON data format.


C++ and IDE
-----------

You may be curious why I chose C++ and wonder which IDE I used.  The explanation is simple, really.  I have been working in a Java shop for the last three years, and not coding C++ at all.  Like most developers I
get excited about using technologies that are outside the day-to-day. No one wants their skills getting too rusty.  Additionally, I thought C++ would provide my interviewers
with a more creative solution, and showcase my knowledge better than my resume.  I honestly haven't written an application in C++ for some time and wasn't familiar with
any modern C++ IDE's, so, I selected QT Creator as it was highly recommended online.  I have never used Creator before this project, but have become very familiar with it these last couple of weeks.  My OS is Fedora 17 x86_64.


Acknowledgements
----------------

Thank you to the kind folks at C2Serve, MongoDB, QT, JQuery, QUnit, GitHub and Fedora for all their hard work on these valuable open-source products.
Big ups to Johnson and Johnson for making the best damn [dental floss](http://www.amazon.com/dp/B001E96PA0/) on the market!
Additional thanks go to SEOmoz for suggesting this project, it was a lot of fun!
