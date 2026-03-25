#!/bin/sh

make re

echo "Capybara, capybara, capybara
Capybara, capybara, capybara
Capybara, capybara, capybara
Capybara, capybara, capybara
South American animal, everyone loves it
Always munching on grass, just chilling out

Capybara, capybara, capybara
Capybara, capybara, capybara
Capybara, capybara, capybara
Capybara, capybara, capybara
With a round body, looks like a big water rat
Two dark eyes, gazing far away

Just like a capybara, spend each day relaxing
Nothing to worry about, just living life
Capybara, capybara, capybara
Capybara, capybara, capybara
Capybara, capybara, capybara
Capybara, capybara, capybara

When I nap, I curl up like a pillow
I just wanna keep finding fun things to do
Just like a capybara, spend each day relaxing
Nothing to worry about, just living life
Capybara, capybara, capybara
Capybara, capybara, capybara
Capybara, capybara, capybara
Capybara, capybara, capybara

I wanna give you a rose
'Cause your name is Capybara
Eating food, splashing in the water
Eating food, then at night, I'll sleep
Capybara, capybara, capybara
Capybara, capybara, capybara
Capybara, capybara, capybara
Capybara, capybara, capybara" > t_capybara

./not_really_better_sed t_capybara "capybara" "pangolin"

echo "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo." > t_loremipsum

./not_really_better_sed t_loremipsum "a" "i"
./not_really_better_sed t_loremipsum.replace "e" "i"
./not_really_better_sed t_loremipsum.replace.replace "o" "i"
./not_really_better_sed t_loremipsum.replace.replace.replace "u" "i"

echo "🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻🌱🐱🌻" > t_cats

./not_really_better_sed t_cats "🌱" "😸"
./not_really_better_sed t_cats.replace "🌻" "😹"