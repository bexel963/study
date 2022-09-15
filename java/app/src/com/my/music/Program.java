package com.my.music;

public class Program {

	public static void main(String[] args) {

		Song hotelCalifornia = new Song("Eagles", "Hotel California", 180100);
		Song heaven  = new Song("Led Zeppelin", "Stairway to Heaven", 172100);
		Song havana  = new Song("Camila Cabello", "Havana", 182200);
		Song santaBaby  = new Song("Ariana Grade", "Santa Baby", 166220);
		Song houndDog  = new Song("Elvis Presley", "Hound Dog", 175220);
		Song basketCase  = new Song("Green Day", "Basket Case", 193000);
		Song christmas  = new Song("Mariah Carey", "All I Want For Christmas Is You", 18301);
		
		System.out.printf("%s by %s. Play time is %d.%s", 
					hotelCalifornia.getName(),
					hotelCalifornia.getArtist(),
					hotelCalifornia.getPlayTimeInMilliSeconds(),
					System.lineSeparator());
		
		System.out.println("===========================================\n");
		PlayList playList1 = new PlayList("Classic Rock");
		playList1.addSong(hotelCalifornia);
		playList1.addSong(heaven);
		playList1.addSong(houndDog);
		
		PlayList playList2 = new PlayList("Millenial");
		playList2.addSong(havana);
		playList2.addSong(santaBaby);
		
		musicPlayer player = new musicPlayer();
		
		player.addSong(hotelCalifornia);
		player.addSong(heaven);
		player.addSong(havana);
		player.addSong(santaBaby);
		player.addSong(houndDog);
		player.addSong(basketCase);
		player.addSong(christmas);
		
		System.out.printf("Song count %d%s", player.getSongCount(), System.lineSeparator());
		System.out.println("===========================================\n");
		player.addPlayList(playList1);
		player.addPlayList(playList2);
		
		player.playSong("Basket Case");
		player.playSong("Hound Dog");
		
		player.playSong("Escape");
		
		player.playPlayList("Classic Rock");
		player.playPlayList("Millenial");
		
		System.out.println("===========================================\n");
		
		playList2.setName("Christmas Music");
		playList2.removeSong("Havana");
		playList2.addSong(christmas);
		
		player.playPlayList("Christmas Music");
		
		System.out.println("===========================================\n");
		
		player.removeSong("Santa Baby");
		player.playPlayList("Christmas Music");
		player.playSong("Santa Baby");
		
		System.out.println("===========================================\n");
		
		player.removePlayList("Christmas Music");
		
		System.out.printf("Song count %d.%s", player.getSongCount(), System.lineSeparator());
		player.playPlayList("Christmas Music");
		
	}

}






























