package com.my.music;

import java.util.ArrayList;

public class musicPlayer {

	private ArrayList<Song> songs;
	private ArrayList<PlayList> playLists;
	
	musicPlayer(){
		this(new ArrayList<Song>(), new ArrayList<PlayList>());
	}
	musicPlayer(ArrayList<Song> songs, ArrayList<PlayList> playList){
		this.songs = songs;
		this.playLists = playList;
	}
	
	public int getSongCount() {
		return this.songs.size();
	}
	public void addSong(Song s) {
		this.songs.add(s);
	}
	
	public void addPlayList(PlayList playList) {
		this.playLists.add(playList);
	}
	public boolean removePlayList(String playListName) {
		for(PlayList playList : this.playLists) {
			if(playListName.equals(playList.getName())) {
				this.playLists.remove(playList);
				return true;
			}
		}
		return false;
	}
	public boolean removeSong(String songName) {
		for(PlayList playList : this.playLists) {
			playList.removeSong(songName);
		}
		
		Song songOrNull = findSongOrNull(songName);
		
		if(songOrNull == null) {
			return false;
		}
		
		this.songs.remove(songOrNull);
		
		return true;
	}
	
	
	
	public void playSong(String songName) {
		Song songOrNull = findSongOrNull(songName);
		
		if(songOrNull == null) {
			System.out.println(String.format("\"%s\" not found!", songName));
			return;
		}
		songOrNull.play();
	}
	public void playPlayList(String playListName) {
		PlayList playList = findPlayListOrNull(playListName);
		
		if(playList == null) {
			System.out.println(String.format("PlayList %s not found!", playListName));
			return;
		}
		playList.play();
	}
	
	private Song findSongOrNull(String songName) {
		for(Song song : this.songs) {
			if(songName.equals(song.getName())) {
				return song;
			}
		}
		return null;
	}
	
	private PlayList findPlayListOrNull(String playListName) {
		for(PlayList playList : this.playLists) {
			if(playListName.equals(playList.getName())) {
				return playList;
			}
		}
		
		return null;
	}
}



















