SELECT AVG(songs.energy) as avg FROM songs JOIN artists ON songs.artist_id = artists.id WHERE artists.name = 'Drake';
