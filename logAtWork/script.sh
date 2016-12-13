cp -r tmp conf/logAtWork && cp -r data conf/logAtWork
cd conf
git add logAtWork && git commit -m 'add conf' && git push
cd ..
